#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
int C,T;
int n,d;
int a[N+5],r[N+5];
int f[N+5],g[N+5];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(C<=10){
			int ans=0;
			for(int i=1;i<=n;i++){
				f[i]=0;
				g[i]=1;
				g[i-1]=0;
				for(int j=i+1,l=i,t=i;j<=n;j++){
					while(l<j&&a[j]-a[l]>d) ++l;
					if(t<l) t=l;
					while(t+1<j&&f[t+1]==f[l]) ++t;
					f[j]=f[l]+1;
					g[j]=min(3ll,g[t]-g[l-1]);
					if(g[j]==2) ++ans;
//					cout<<i<<" "<<j<<" "<<l<<" "<<t<<" "<<f[j]<<" "<<g[j]<<'\n';
					g[j]+=g[j-1];
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		r[n]=n;
		for(int i=n-1;i>=1;i--){
			r[i]=r[i+1];
			while(r[i]>i&&a[r[i]]-a[i]>d) --r[i];
		} 
		int ans=0;
		for(int i=n;i>=1;i--){
			if(r[i]!=i){
				f[i]=r[i]-r[i-1]+(r[i]>r[i-1]?f[r[i]]:0);
				if(r[r[i]-1]<r[r[i]]) g[i]=g[r[i]]-(r[r[i]]>=r[i]+2&&r[r[i]-1]==r[r[i]]-1?r[r[r[i]]-1]-r[r[r[i]]-2]:0);
				else g[i]=0;
				if(r[i]>=i+2){
					g[i]+=r[r[i]-1]-r[r[i]-2];
					if(r[r[i]-2]<r[r[i]-1]&&r[r[i]-1]==r[r[i]]) g[i]+=f[r[r[i]]];
				}
			}
			else{
				f[i]=0;
				g[i]=0;
			}
			ans+=g[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
