#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
const ll inf=1e18;
int c,n,m,d,q,w[M],k[N],a[M],t[M],g[N][M];
ll ans,interchange[N][N];
vector<int>Line[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[j]>>t[j],Line[a[j]].push_back(i);
		for(int j=1;j<=k[i];j++) g[i][a[j]]=t[j];
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) interchange[i][j]=inf;
	for(int i=1;i<=n;i++) interchange[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)Line[i].size();j++){
			for(int k=0;k<(int)Line[i].size();k++){
				ll a=(ll)g[Line[i][j]][i],b=(ll)g[Line[i][k]][i];
				interchange[Line[i][j]][Line[i][k]]=min(interchange[Line[i][j]][Line[i][k]],a+b);
			}
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) interchange[i][j]=min(interchange[i][j],interchange[i][k]+interchange[k][j]);
	for(int i=1,s,t;i<=q;i++){
		cin>>s>>t;
		ans=inf;
		for(int j=0;j<(int)Line[s].size();j++){
			for(int k=0;k<(int)Line[t].size();k++){
				ll LineS=Line[s][j],LineT=Line[t][k];
				ans=min(ans,interchange[LineS][LineT]+w[s]+w[t]+g[LineS][s]+g[LineT][t]);
			}
		} 
		cout<<ans<<'\n';
	}
	return 0;
}
