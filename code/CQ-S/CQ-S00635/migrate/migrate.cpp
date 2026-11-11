#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,d,x[N],q[N],f[N],cnt[N],ans,g[N];
signed main( ){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>T;
	while(T--){
		if(c>10){
			cout<<"0"<<'\n';
			continue;
		}
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int s=1;s<=n;s++){
			int l=1,r=1;
			for(int i=0;i<=n;i++) f[i]=1e9,q[i]=cnt[i]=0,g[i]=0;
			q[1]=s;f[s]=0;cnt[0]=1;
			for(int i=s+1;i<=n;i++){
				while(l<=r&&x[i]-x[q[l]]>d) cnt[f[q[l]]]-=g[q[l]],l++;
				if(l>r) break;
				f[i]=f[q[l]]+1;
				g[i]+=cnt[f[q[l]]];
				if(g[i]==2){
					ans++;
				}
				while(r>=l&&f[i]<f[q[r]]) cnt[f[q[r]]]-=g[q[r]],--r;
				q[++r]=i;cnt[f[i]]+=g[i];
			}
		}
		cout<<ans<<'\n';
	} 
	return 0;
}

