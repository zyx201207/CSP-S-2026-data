#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,k;
int w[510000];
struct asd{
	int v,w;
};
vector<asd>qq1[510000];
ll qq[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			ll x1,x2;cin>>x1>>x2;
			qq1[x1].push_back({i,x2});
		}
	}
	memset(qq,0x3f,sizeof qq);
	for(int i=1;i<=m;i++){
		if(qq1[i].size()<=1)continue;
		for(int j=0;j<qq1[i].size();j++){
			for(int k=1;k<qq1[i].size();k++){
				if(j==k)continue;
				qq[qq1[i][j].v][qq1[i][k].v]=qq1[i][k].w+qq1[i][j].w;
				qq[qq1[i][k].v][qq1[i][j].v]=qq1[i][k].w+qq1[i][j].w;
				//cout<<qq1[i][j].v<<" "<<qq1[i][k].v<<" "<<qq[qq1[i][j].v][qq1[i][k].v]<<"\n";
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			qq[i][i]=0;
			for(int j=1;j<=n;j++){
				qq[i][j]=min(qq[i][j],qq[i][k]+qq[j][k]);
				qq[j][i]=qq[i][j];
			}
		}
	}/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<i<<" "<<j<<": "<<qq[i][j]<<"\n";
		}
	}*/
	//for(int i=1;i<=m;i++)cout<<qq1[i].size()<<" ";
	for(int i=1;i<=q;i++){
		int a,b;cin>>a>>b;long long ans=1e18;
		for(int i=0;i<qq1[a].size();i++){
			for(int j=0;j<qq1[b].size();j++){
				//cout<<qq1[a][i].v<<" ";
				int a1=qq1[a][i].v,a2=qq1[b][j].v;
				int w1=qq1[a][i].w,w2=qq1[b][j].w;
				ans=min(ans,1LL*qq[a1][a2]+w[a]+w[b]+w1+w2);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
