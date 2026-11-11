#include <bits/stdc++.h>
using namespace std;

namespace tymxz{
	typedef long long ll;
	const int N=2e6+7,inf=1e9+7;
	int n;
	ll d,x[N],ans;
	int f1[N],f2[N],dp[N];
	int c1[N],c2[N];
	vector<int> g1[N],g2[N];
	int fir[N],las[N],mx;
	void solve(int c){
		if(c==mx) return;
		for(int i=fir[c]+1;i<=las[c];i++){
			if(f1[las[c+1]]==fir[c+1]&&f1[i]==las[c+1]) ans+=c2[fir[c]];
			if(fir[c]+1<i&&f1[i]==fir[c]) ans+=c2[fir[c]+1];
		}
	}
	void subt(){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		x[n+1]=x[n];
		int f,c=0;
		for(int i=n;i>=1;){
			f=i;
			if(x[i]>=x[i+1]-d){
				while(f>=1&&x[f]>=x[i+1]-d) f--;
				c++;
				fir[c]=f+1,las[c]=i;
				i=f;
			}else{
				while(f>=1&&x[f]>=x[i]-d) f--;
				c++;
				fir[c]=f+1,las[c]=i;
				i=f;
			}
			for(int j=fir[c];j<=las[c];j++) dp[j]=c;
			//cout<<fir[c]<<" "<<las[c]<<endl;
		}
		mx=c;
		for(int i=1;i<=n;i++){
			f1[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
			f2[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			g1[i].clear(),g2[i].clear();
		}
		for(int i=1;i<=n;i++) g1[f1[i]].push_back(i);
		for(int i=n;i>=1;i--){
			c1[i]=0;
			for(int x:g1[i]) if(dp[x]!=dp[i]) c1[i]+=(f2[i]==x?1+c1[x]:1); 
		}
		for(int i=1;i<=n;i++) g2[f2[i]].push_back(i);
		for(int i=1;i<=n;i++){
			c2[i]=0;
			for(int x:g2[i]) if(dp[x]!=dp[i]) c2[i]+=(f1[i]==x?1+c2[x]:1);
		}
		for(int i=1;i<n;i++) if(dp[i]==dp[i+1]) ans+=1ll*c1[i]*c2[i+1];
		for(int i=1;i<=c;i++) solve(i);
		cout<<ans<<endl;
	}
}
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) tymxz::subt();
	return 0;
} 
