#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 510;
const int M = 5e5+10;
ll c,n,m,d,q;
ll w[M],bian[N][N];
ll xq,yq,ans;

struct node{
	ll a,t; 
};

vector<node>lmt[M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll nowa,nowt;
			cin>>nowa>>nowt;
			lmt[nowa].push_back((node){i,nowt});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			bian[i][j]=1e18+10;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<lmt[i].size();j++){
			for(int k=j+1;k<lmt[i].size();k++){
				ll aj=lmt[i][j].a,ak=lmt[i][k].a;
				bian[aj][ak]=min(bian[aj][ak],lmt[i][j].t+lmt[i][k].t);
				bian[ak][aj]=bian[aj][ak];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				bian[i][j]=min(bian[i][j],bian[i][k]+bian[k][j]);
			}
		}
	}
	while(q--){
		cin>>xq>>yq;
		ans=1e18+10;
		for(int i=0;i<lmt[xq].size();i++){
			for(int j=0;j<lmt[yq].size();j++){
				ans=min(ans,w[xq]+lmt[xq][i].t+bian[lmt[xq][i].a][lmt[yq][j].a]+lmt[yq][j].t+w[yq]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

