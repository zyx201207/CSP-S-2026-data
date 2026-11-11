#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=200005;

int n,m;
int a[N],f[N];
int c[N][30];
int cnt[30];

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=a[i];
		int j=0;
		while(k>0){
			//cout<<(k&1);
			if(k%2==0){
				c[i][j]=1,cnt[j]++;
			}
			j++;k>>=1;
		}
		//cout<<' '<<j<<'\n';
		for(;j<=30;j++){
			c[i][j]=1,cnt[j]++;
		}
	}
	
	int r=n-m;
//	cout<<"ok\n";
	for(int j=30;j>=0;j--){
		//cout<<cnt[j]<<'\n';
		if(!cnt[j]) continue;
		if(cnt[j]>r) continue;
		r-=cnt[j];
		//cout<<"cut\n";
		//cout<<r<<'\n';
		for(int i=1;i<=n;i++){
			if(f[i]) continue;
			if(c[i][j]){
				f[i]=1;
				for(int k=0;k<=30;k++){
					if(c[i][k]){
						cnt[k]--;
						c[i][k]=0;
						if(cnt[k]<0) cnt[k]=0;
					}
				}
				//if(c[i][0]) cout<<"wef!\n";
			}
		}
	}
	//cout<<cnt[0]<<'\n';
	
	int ans=0;
	for(int i=0;i<=30;i++){
		//cout<<cnt[i]<<' ';
		if(!cnt[i]) ans+=(1<<i);
	}
	
	/*for(int i=1;i<=n;i++){
		if(!f[i]) cout<<a[i]<<' ';
	}*/
	
	cout<<ans;
	
	return 0;
} 
