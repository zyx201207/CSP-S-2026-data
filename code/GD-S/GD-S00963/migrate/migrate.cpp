#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int ans=N;
int vis;
int a[N];
int n,d;
void dfs(int u,int v,int w){
	if(u==v){
		if(ans==w)vis++;
		else if(ans>w){
			ans=w;
			vis=1;
		}
		return;
	}
	if(w>ans)return;
	for(int i=u+1;i<=v;i++){
		if(a[i]-a[u]<=d){
			dfs(i,v,w+1);
		}
		else{
			break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int x=0;
		bool ok=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2){
				x=a[i]-a[i-1];
			}
			else if(i!=1){
				if(x!=a[i]-a[i-1]){
					ok=0;
				}
			}
		}
		if(ok==1){
			x=d/x;
			int ans=0;
			if(x+2==n&&x%2==0){
				cout<<1<<endl;
				continue;
			}
			for(int j=1;j<=n;j++){
				if(x*j+2>=n)break;
				ans+=(x*j)*(n-x*j-2);
			}
			cout<<ans<<endl;
		}
		else if(n<=300){
			int s=0;
			for(int i=1;i<=n;i++){
				for(int j=i+2;j<=n;j++){
					ans=N;
					vis=0;
					dfs(i,j,0);
					if(vis==2)s++;
				}
			}
			cout<<s<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
	return 0;
}

