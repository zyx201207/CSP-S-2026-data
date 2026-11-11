#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define _ 505
#define __ 500005
using namespace std;
int c,n,m,d,q;//m:the number of subways
ll w[__],f[_][_],vis[_][_];
bool visited[__];
vector<pair<int,ll> >line[__];
vector<int>trans[__];
ll F(int x,int y){//x->y
	if(f[x][y])
		return f[x][y];
	int len=trans[x].size();
	ll res=LLONG_MAX>>2;
	rep(i,0,len-1){//<=d
		int id=trans[x][i];
		if(!vis[id][y])
			continue;
		res=min(res,vis[id][x]+vis[id][y]);
	}
	return f[x][y]=res;
}
//priority_queue<pair<int,ll>,vector<pair<int,ll> >,greater<pair<int,ll> > >q;
int main(){
	freopen("subway.in" ,"r",stdin );
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	rep(i,1,m)
		scanf("%lld",&w[i]);
	rep(i,1,n){
		int len;
		scanf("%d",&len);
		while(len--){
			int x;
			ll  t;
			scanf("%d%lld",&x,&t);
			trans[x].push_back(i);
			vis[i][x]=t;//*****
			line[i].push_back({x,t});
		}
	}
	rep(k,1,m)
		rep(i,1,m)
			rep(j,1,m)
				f[i][j]=min(F(i,j),F(i,k)+F(k,j));
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",w[x]+w[y]+F(x,y));
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
