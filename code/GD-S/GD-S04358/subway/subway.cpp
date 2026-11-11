#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pil pair<int,long long>
#define mkpir make_pair  
const int N=5e5+700;
const int M=5e2+7;

void inpput(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}

inline ll read(){
	ll r=1;
	ll w=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')r*=-1;
		c=getchar();
	}
	
	while(c>='0'&&c<='9'){
		w=w*10+c-'0';
		c=getchar();
	}
	return r*w;
} 

int c,n,m,d,q;

int w[N],k[M];
vector<vector<pii>> g;

void init(){
	
	c=read();n=read();m=read();d=read();q=read();
	
	
	for(int i=1;i<=m;i++){
		w[i]=read();
	}	
	int a,t;
	g.resize(m+n+7);
	 
	for(int i=1;i<=n;i++){
		k[i]=read();
		
		
		for(int j=1;j<=k[i];j++){
			
			a=read();t=read();
			
			g[i+m].push_back(mkpir(a,t));
			g[a].push_back(mkpir(i+m,t));
			
		}
	}
	
	for(int i=1;i<=m;i++){
		for(auto v:g[i]){
//			printf("%d-->%d time=%d\n",i,v.first,v.second);
		}
		
//		printf("\n");
		
	}
	
}

map<pii, ll> mp;

struct cmp{
	bool operator()(pii A,pii B){
		return A.second>B.second;
	}
};

bool vis[N];

void dijk(int st){
	priority_queue<pil,vector<pil>,cmp> pq;
	pq.push(mkpir(st,0));
	memset(vis,0,sizeof(vis));
	
	int id;
	
	while(!pq.empty()){
		pii p=pq.top();pq.pop();
		
		id=p.first;
		if(vis[id])continue;
		vis[id]=true;
		if(id!=st){
			mp[mkpir(id,st)]=p.second;
			mp[mkpir(st,id)]=p.second;
		}
		
		for(auto to:g[id]){
			pq.push(mkpir(to.first,to.second+p.second));
		}
		
	}
	return;
}

int main(){
	
	inpput();
	
	init();
	
	int x,y;
	ll co;
	
	while(q--){
		
		x=read();y=read(); 
		if(x>y)swap(x,y);
		
		co=1ll*(w[x]+w[y]);
		
		if(mp.count(mkpir(x,y))){
			printf("%lld\n",mp[mkpir(x,y)]+co);
			
		}else{
			
			dijk(x);
			printf("%lld\n",mp[mkpir(x,y)]+co);
			
		}
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
*/

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
 
