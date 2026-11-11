/*
-fsanitize=address,undefined

ios::sync_with_studio(0);
cin.tie(0);

cout<<fixed<<precision();

u\to v，恰好两条最短路径，称为双径岛屿对 

想到15:45 

- (u,v)相邻，一定非法 
- 可以划分出连通块，不连通的非法 
- 两个路径只能有其中一个不同 

目前没有想到部分分，先写T2(15:50) 

思考10min正解(16:37) 

不是合法点对当且仅当存在>1个不同的走法 

目前有n^2做法 

40pts，先写 
*/
#include <bits/stdc++.h>
#define ll long long
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define ROF(i,r,l) for(int i=(r);i>=(l);--i)
#define pii pair<int,int>
#define mkp make_pair
#define fir first
#define sec second
using namespace std;

namespace mycode{
	const int MAXN=2e6+5;
	deque<pii > q;//权值，下标 
	ll ans=0;
	ll X[MAXN],D;
	int d[MAXN],fa[MAXN],R[MAXN],L[MAXN],n;
	
	void getD(int x){//x向左 
		d[x]=0;while(!q.empty()) q.pop_back();q.push_back(mkp(0,x));
		ROF(i,x-1,1){
			if(R[i]<i+1) break;
			while(q.front().sec>R[i]) q.pop_front();
			d[i]=q.front().fir+1;fa[i]=q.front().sec;
			while(!q.empty()&&q.back()>mkp(d[i],i)) q.pop_back();
			q.push_back(mkp(d[i],i));
		}
	}
	
	bitset<MAXN> fushu,two;
	
	void check(int x){//x向左 
		fushu[x]=0;two[x]=0;
		ROF(i,x-1,1){
			two[i]=fushu[i]=0;
			if(R[i]<i+1) break;
			if(min(R[i],x)==fa[i]){//只有一个选择 
				if(fushu[fa[i]]) fushu[i]=1;
				if(two[fa[i]]) two[i]=1,++ans;
			}else if(min(R[i],x)==fa[i]+1){//恰好两个选择 
				fushu[i]=1;
				if(!fushu[fa[i]]&&!fushu[fa[i]+1]) two[i]=1,++ans;
			}else fushu[i]=1;
		}
//		FOR(i,1,x) printf("%d,",fa[i]);printf("\n");
	}
/*
当有>2个选择是，fushu=1 
当x->dep+1有两个选择时，fushu=1 
- 当两个fushu均为0时，这个点合法 
- 有一个=1，就不合法
当只有一个选择时，看前方的是否two，是则two=1，合法 
*/
	
	void prework(){
		int r=1;
		FOR(i,1,n){
			while(r<n&&X[r+1]-X[i]<=D) ++r;
			R[i]=r;
		}
		int l=n;
		ROF(i,n,1){
			while(l>1&&X[i]-X[l-1]<=D) --l;
			L[i]=l;
		}
	}
	
	void work(){
		ans=0;
		scanf("%d%lld",&n,&D);
		FOR(i,1,n)scanf("%lld",&X[i]);
		prework();
		FOR(i,2,n){
			getD(i);check(i);
		}
		printf("%lld\n",ans);
	}
	
	int main(){
		int c,T;scanf("%d%d",&c,&T);
		while(T--)work();
		return 0;
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	mycode::main();
	return 0;
}
