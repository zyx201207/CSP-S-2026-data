#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct Data{
	int num;
	pair<int,int> Ways[25];
}Nodes[N];
int a[N],dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x7fffffff,sizeof(dis));
	for(int i=1;i<=500;i++)
		dis[i][i]=0;
	int c,n,m,d,q,k,x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin>>aa>>tt;
			Nodes[aa].num++;
			Nodes[aa].Ways[Nodes[aa].num]=make_pair(i,tt);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=Nodes[i].num;j++)
			for(int p=j+1;p<=Nodes[i].num;p++){
				int na=Nodes[i].Ways[j].first,nb=Nodes[i].Ways[p].first;
				int ma=Nodes[i].Ways[j].second,mb=Nodes[i].Ways[p].second;
				if(dis[na][nb]>ma+mb)
					dis[na][nb]=ma+mb;
				if(dis[nb][na]>ma+mb)
					dis[nb][na]=ma+mb;
			}
	}
	while(q--){
		int ans=0x7fffffff;
		cin>>x>>y;
		for(int i=1;i<=Nodes[x].num;i++)
			for(int j=1;j<=Nodes[y].num;j++){
				int na=Nodes[x].Ways[i].first,nb=Nodes[y].Ways[j].first;
				int ma=Nodes[x].Ways[i].second,mb=Nodes[y].Ways[j].second;
				int sum=dis[na][nb]+a[x]+a[y]+ma+mb;
				ans=min(ans,sum);
			}
		cout<<ans<<"\n";
	}
	return 0;
}
