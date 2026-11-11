#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,inf=1e18;
int n,d,a[N],ans,f[N],g[N];
void sol(){
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		f[i]=0;g[i]=1;
		for(int j=i+1;j<=n;j++){
			f[j]=inf;
			for(int k=i;k<j;k++){
				if(a[k]+d>=a[j]){
					if(f[j]>f[k]+1)f[j]=f[k]+1,g[j]=0;
					if(f[j]==f[k]+1)g[j]+=g[k];
				}
			}
			if(g[j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T>>T;while(T--)sol(); 
	return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63

*/
