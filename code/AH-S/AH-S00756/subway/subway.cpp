#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int l[505];
vector<int>x[500005];
vector<long long>y[500005];
int u,t;
int st,en;
long long flyd[505][505];
int s[5000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(flyd,0x1f,sizeof(flyd));
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=m;i++){
		flyd[i][i]=0;
		cin>>l[i];
		for(int j=1;j<=l[i];j++){
			cin>>u>>t;
			x[u].push_back(i);
			y[u].push_back(t);
		}
	}
	for(int i=1;i<=n;i++){
		int ll=x[i].size();
		for(int j=0;j<ll;j++){
			for(int k=j+1;k<ll;k++){
				flyd[x[i][j]][x[i][k]]=flyd[x[i][k]][x[i][j]]=min(flyd[x[i][j]][x[i][k]],y[i][j]+y[i][k]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				flyd[i][j]=min(flyd[i][j],flyd[i][k]+flyd[k][j]);
			}
		}
	}
	while(q--){
		cin>>st>>en;
		long long ans=0x3f3f3f3f3f3f3f;
		for(int i=0;i<(int)x[st].size();i++){
			for(int j=0;j<(int)x[en].size();j++){
				ans=min(ans,flyd[x[st][i]][x[en][j]]+y[st][i]+y[en][j]);
			}
		}
		cout<<s[st]+s[en]+ans<<'\n';
	}
	return 0;
}
