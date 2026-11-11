#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
const int INF=1e7;
int c,t,n,f[N],g[N];
ll d,x[N],ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d; ans=0;
		for(int i=1;i<=n;++i)cin>>x[i],f[i]=g[i]=0;
		if(n<=1000){
			for(int i=1;i<=n;++i){
				if(x[i+1]-x[i]>d)continue;
				for(int j=i+1;j<=n;++j){
					for(int k=i+1;k<=j;++k)f[k]=INF,g[k]=0;
					f[i]=0; g[i]=1;
					int l=i;
					for(int k=i+1;k<=j;++k){
						while(l<k&&x[k]-x[l]>d)++l;
						for(int p=l;p<k;++p){
							if(f[p]!=INF&&f[p]+1>f[k])break;
							if(f[p]+1<f[k]){
								f[k]=f[p]+1;
								g[k]+=g[p];
								if(g[k]>2){
									g[k]=3;
									break;
								} 
							}else if(f[p]+1==f[k]){
								g[k]+=g[p];
								if(g[k]>2){
									g[k]=3; break;
								}
							}
						}
					}
					if(g[j]==2){
						++ans;
					}
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		bool fla=1;
		for(int i=3;i<=n;++i){
			if(x[i]-x[i-1]!=x[i-1]-x[i-2]){
				fla=0; break;
			}
		}
		if(fla){
			if(x[2]-x[1]>d){
				cout<<"0\n";
				continue;
			}
			int cnt=0;
			for(int i=2;i<=n;++i){
				if(x[i]-x[1]>d){
					cnt=i-1;
					break;
				}
			}
			cnt=(cnt-1)*2;
			cout<<max(0,n-cnt+1)<<'\n';
		}
	}
	return 0;
}
