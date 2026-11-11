#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c_,T_;
namespace Solve1_{
	const int maxn=5004;
	int n;ll m;
	ll a[maxn];
	int to[maxn],f[maxn][maxn],s[maxn];
	int L[maxn];
	void Solve(){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		to[n]=n;
		for(int i=n-1;i>=1;i--){
			to[i]=to[i+1];
			while(a[to[i]]-a[i]>m) to[i]--;
		}
		for(int i=n;i>=1;i--){
			f[i][i]=0;
			for(int j=i+1;j<=to[i];j++) f[i][j]=1;
			for(int j=to[i]+1;j<=n;j++) f[i][j]=f[to[i]][j]+1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(i==to[i]){
				for(int j=i;j<=n;j++) f[i][j]=maxn;
				continue;
			}
			L[0]=i;
			int len=f[i][n];
			for(int j=i+1;j<=n;j++){
				if(f[i][j]>n){
					len=f[i][j-1];
					break;
				}
				if(f[i][j]>f[i][j-1]) L[f[i][j]]=j;
			}L[len+1]=n+1;
			s[i-1]=1;
			for(int j=i;j<=n;j++) s[j]=0;
			for(int j=i;j<=n;j++){
				if(f[i][j]>n) break;
				s[j]+=s[j-1];
				ans+=(s[j]==2);
				if(f[i][j]<len) s[L[f[i][j]+1]]+=s[j],s[min(to[j]+1,L[f[i][j]+2])]-=s[j];
				if(j==i) s[j]=0;
			}
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c_>>T_;
	if(c_<=10) while(T_--) Solve1_::Solve();
	return 0;
}

