#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

inline void print(int x){
	stack<char> s;
	do{
		s.push(x%10+'0');
		x/=10;	
	}while(x);
	while(!s.empty()){
		putchar(s.top());		
		s.pop();	
	}
}
const int M=5e5+10,N=510;
vector<pair<int,int>> e[N];
bool in[M];
ll dis[M];
class E{
	public:
		int x;
		ll w;
		bool operator < (E b) const {
			return w<b.w;
		}
		void makeing(int a,ll b){
			x=a;
			w=b;
		}
};
E make(int a,ll b){
	E ls;
	ls.makeing(a,b);
	return ls;
}
void spfa(int go){
	set<E> q;
	q.insert(make(go,0));
	while(!q.empty()){
		E ls=*(q.begin());
		int x=ls.x;
		for(int i=0;i<e[x].size();++i){
			if(dis[e[x][i].first]>dis[x]+e[x][i].second){
				dis[e[x][i].first]=dis[x]+e[x][i].second;
				q.insert(make(e[x][i].first,dis[e[x][i].second]));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	int cnt=m*2;
	for(int i=1;i<=m;++i){
		int x=read();
		e[i].push_back(make_pair(i+m,x));
		e[m+i].push_back(make_pair(i,x));
	}
	for(int i=1;i<=n;++i){
		int cd=read();
		bool o=1;
		while(cd--){
			int x=read(),y=read();
			e[++cnt].push_back(make_pair(x+m,y));
			e[x+m].push_back(make_pair(cnt,y));
			if(!o){
				e[cnt].push_back(make_pair(cnt-1,0));
				e[cnt-1].push_back(make_pair(cnt,0));
			}
			o=0;
		}
	}
	while(q--){
		for(int i=1;i<=m;++i){
			dis[i]=LLONG_MAX;
			in[i]=0;
		}
		int u=read(),v=read();
		spfa(u);
		print(dis[v]);
	}
	return 0;
}
