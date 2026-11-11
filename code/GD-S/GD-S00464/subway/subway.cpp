#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct poi{
	int tv;
	long long tw;
//get-poi
};
struct ques{
	int id,st,ed;
//question 
}lt[500005];//question-list
bool cmb(ques tx,ques ty){
	return tx.st<ty.st;
//sort-by-start
}
long long ans[500005];
vector<poi>g[20505];
long long dis[20005],a[20005];
int c,n,m,d,q;
//n-xianlu,m-zhandian,d-jingguo,q-chaxun
priority_queue<pair<long long,int> >pq;
//get-dis
void dijk(int fm,int en){
	for(int i=1;i<=m+n;i=i+1)dis[i]=0x3f3f3f3f3f3f3f3f;
	int tu=lt[fm].st,ty;
	long long tz;
	while(pq.empty()==false)pq.pop();
	dis[tu]=0;
	pq.push({0,tu});
	while(pq.empty()==false){
		tu=pq.top().second;
		tz=-pq.top().first;
		pq.pop();
		if(dis[tu]<tz)continue;
		for(int i=0;i<g[tu].size();i=i+1){
			ty=g[tu][i].tv;
			tz=g[tu][i].tw;
			if(dis[ty]<=dis[tu]+tz)continue;
			dis[ty]=dis[tu]+tz;
			pq.push({-dis[ty],ty});
		//add-point
		}
	//dijk
	}
	for(int i=fm;i<=en;i=i+1)ans[lt[i].id]=dis[lt[i].ed]+a[lt[i].st]+a[lt[i].ed];
	//update
	return;
//get-dis
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	int tx,ty;
	long long tz;
	for(int i=1;i<=m;i=i+1)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i=i+1){
		scanf("%d",&tx);
		for(int j=1;j<=tx;j=j+1){
			scanf("%d%lld",&ty,&tz);
			g[m+i].push_back({ty,tz});
			g[ty].push_back({m+i,tz});
		//a->m+i->b-->1line(vrpoint)
		}
	//get-1-line
	}
	for(int i=1;i<=q;i=i+1){
		lt[i].id=i;
		scanf("%d%d",&lt[i].st,&lt[i].ed);
	//input-ques
	//wait-for-ques
	}
	sort(lt+1,lt+q+1,cmb);
	tx=1;
	for(int i=1;i<=q+1;i=i+1){
		if(lt[i].st!=lt[tx].st){
			//printf("do-%d:\n",lt[tx].st);
			dijk(tx,i-1);
			tx=i;
		//from-tx-to-i-1
		}
	//get-dis-together
	}
	for(int i=1;i<=q;i=i+1)printf("%lld\n",ans[i]);
	return 0;
//subway-T2
//测试样例通过情况：001ok. 002ok. 003ok. 004ok. 005tle
//检查情况： 18:13:08.92
}
