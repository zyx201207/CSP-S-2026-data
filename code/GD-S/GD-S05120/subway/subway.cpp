#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3fLL;
const int N=1e4+5;
int c,n,m,d,q,w[N],k[N],a[N][N],t[N][N],x[N],y[N];
bool tong[N][N];
void input(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	input();
	for(int i=1;i<=k[1];i++){
		for(int j=1;j<=k[2];j++){
			if(a[1][i]==a[2][j])tong[1][i]=true;
		}
	}
	for(int i=1;i<=k[2];i++){
		for(int j=1;j<=k[3];j++){
			if(a[2][i]==a[3][j])tong[2][i]=true;
		}
	}
	for(int plan=1;plan<=q;plan++){
		int ans=0;
		ans+=w[x[plan]]+w[y[plan]];
		int starts=0,ends=INF;
		for(int train=1;train<=n;train++){
			for(int st=1;st<=k[train];st++){
				if(a[train][st]==x[plan])starts=train;
				if(a[train][st]==y[plan])if(ends==INF)ends=train;
			}
		}
		ans+=t[starts][x[plan]]+t[ends][y[plan]];
		if(starts!=ends){
			for(int j=starts;j<ends;j++){
				for(int i=1;i<=k[starts];i++){
					if(tong[j][i])ans+=(t[j][i]+t[j+1][i]);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
