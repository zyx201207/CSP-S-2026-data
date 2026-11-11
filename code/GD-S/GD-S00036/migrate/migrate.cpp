#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int c,n,d,a[N],f[N],g[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)	cin>>a[i];
	int ans=0;
	for(int i=1;i<n;i++){
		memset(f,0,sizeof(f));
		memset(g,0x3f,sizeof(g));
		g[i]=0;
		f[i]=1;
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<j;k++){//k->j 
				if(a[j]-a[k]>d)	continue;
				if(g[k]+1<g[j]){
					g[j]=g[k]+1;
					f[j]=f[k];
				}
				else if(g[k]+1==g[j])	f[j]+=f[k];	
			}
			if(f[j]==2)	ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T;cin>>c>>T;
	while(T--)	solve();
	
	return 0;
}
/*
24·Ö 
*/
