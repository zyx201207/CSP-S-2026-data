#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[2000005];
int nxt[2000005];
int pre[2000005];
bitset<2000005>vis,zero;
int main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(15<=c&&c<=18){
			int t=a[2]-a[1];
			if(2*t<=d&&d<3*t){
				int cnt=0;
				for(int i=n-(n&1);i>=4;i-=2)cnt+=n+1-i;
				cout<<cnt<<endl;
				continue;
			}else{
				cout<<0<<endl;
				continue;
			}
		}
		
		int x=1;
		for(int i=1;i<=n;i++){
			while(x<=n&&a[x]-a[i]<=d)x++;
			x--;
			nxt[i]=x;
		}
		x=n;
		for(int i=n;i>=1;i--){
			while(x>=1&&a[i]-a[x]<=d)x--;
			x++;
			pre[i]=x;
		}
		nxt[n]=n+1;
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				vis&=zero;
				int o=i;
				int f=0;
				for(;o<=j;o=nxt[o]){
					if(o==nxt[o]){
						f=-1;
						break;
					}
					vis[o]=1;
				}
				o=j;
				vis[j]=1;
				
				for(;o>=i;o=pre[o]){
					if(o==pre[o]){
						f=-1;
						break;
					}
					if(!vis[o]&&f==0)f=1;
					if(o!=i&&vis[o]&&f==1)f=2;
					if(!vis[o]&&f==2)f=3;
				}
				if(f==2||f==1){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

