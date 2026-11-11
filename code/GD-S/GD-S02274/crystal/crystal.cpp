#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int a[N];//dp[i]表示在地i次操作上，最多用dp[i] 可合成 
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7 
bool cmp(int x,int y){
	return x>y;
}int g[N];
signed main(){
	freopen("cystal.in","r",stdin);
	freopen("cystal.out","w",stdout);
	int n,p;cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	int all=0;
	for(int i=1;i<=n;i++){
		int m=p,ans=0;
		memset(g,0,sizeof(g));
		int cnt=n;
		for(int j=1;j<=n;j++){
			if(a[i]-a[j]>=0)g[j]=a[i]-a[j];
			else g[j]=1e15;
		}
		sort(g+1,g+1+n);
		for(int j=1;j<=n;j++){
			//cout<<i<<' '<<j<<" "<<g[j]<<';'<<m<<"R"<<ans<<endl;
					if(m==0){
						break;
					}
			if(g[j]!=1e15){
				if(g[j]<=m){
					m-=g[j];
					ans++;

				}
				else {
					break;
				}
			}else{
				break;
			}
			//cout<<i<<' '<<j<<" "<<g[j]<<';'<<m<<"R"<<ans<<"KK"<<endl;
		}
		all=max(all,ans);
	}cout<<all;
	return 0;
}
