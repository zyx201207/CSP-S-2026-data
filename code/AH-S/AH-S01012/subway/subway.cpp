#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int cc,n,m,dd,q,w[500005];
long long d[505][505];
vector<pair<int,long long> > pos[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d,0x3f,sizeof(d));
	scanf("%d%d%d%d%d",&cc,&m,&n,&dd,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
//	cout<<"ok";
	for(int i=1;i<=m;i++){
		int k,ps;
		long long c;
		scanf("%d",&k);
		while(k--){
			scanf("%d%lld",&ps,&c);
			pos[ps].push_back(make_pair(i,c));
//		cout<<"K="<<k<<"\n";
		}
	}
//	cout<<"ok";
	for(int i=1;i<=n;i++)
		for(int j=0;j<pos[i].size();j++){
			int ps1=pos[i][j].first;
			long long w1=pos[i][j].second;
			for(int k=j+1;k<pos[i].size();k++){
				int ps2=pos[i][k].first;
				long long w2=pos[i][k].second;
				d[ps1][ps2]=min(d[ps1][ps2],w1+w2);
				d[ps2][ps1]=d[ps1][ps2];
			}
		}
	for(int i=1;i<=m;i++)
		d[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				if(i!=j&&i!=k&&k!=j)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--){
		int ff,tt;
		scanf("%d%d",&ff,&tt);
		long long ans=1ll<<55;
		for(int i=0;i<pos[ff].size();i++)
			for(int j=0;j<pos[tt].size();j++){
				int ps1=pos[ff][i].first,ps2=pos[tt][j].first;
				ans=min(ans,pos[ff][i].second+d[ps1][ps2]+pos[tt][j].second);
			}
		printf("%lld\n",ans+w[ff]+w[tt]);
	}
	return 0;
}
