#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[100005],timeq[505][5005];
struct infor{
	long long number;
	 long long place;
};
vector<vector<infor>> luxi(100005);
bool check[10005];
long long min_time;
void dfs(long long xian,long long di,long long sum,long long mudidi){
	if(di==mudidi){
		min_time=min(min_time,sum+timeq[xian][mudidi]);
		return ;
	}
	for(int i=0;i<=luxi[di].size()-1;i++){
		if(check[luxi[di][i].place]==0){
			check[luxi[di][i].place]=1;
			if(xian==luxi[di][i].number){
				dfs(xian,luxi[di][i].place,sum,mudidi);
			}
			else dfs(luxi[di][i].number,luxi[di][i].place,sum+timeq[xian][di]+timeq[luxi[di][i].number][di],mudidi);
			check[luxi[di][i].place]=0;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long k;
		vector<long long> di2(10005);
		for(int j=1;j<=k;j++){
			long long di,time2;
			cin>>di>>time2;
			di2.push_back(di);
			timeq[i][di]=time2;
		}
		for(int j=0;j<=k-2;j++){
			for(int t=j+1;t<=k-1;t++){
				luxi[j].push_back({i,t});
				luxi[t].push_back({i,j});
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		long long sum_time=w[x]+w[y];
		min_time=10101010010101ll;
		for(int j=1;j<=m;j++){
			check[j]=0;
		}
		for(int j=0;j<=luxi[x].size()-1;j++){
			dfs(luxi[x][j].number,x,sum_time+timeq[luxi[x][j].number][x],y);
		}
		cout<<min_time<<endl;
	}
	return 0;
}
