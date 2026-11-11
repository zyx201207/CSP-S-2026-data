#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const long long INF=1e18;
struct T{
	int x,y,id;
} qu[N];
template<class T>
struct Q{
	T f[N];
	int head=1,tail=0;
	void push(T x){f[++tail]=x;}
	T front(){return f[head];}
	void pop(){++head;}
	bool empty(){return head==tail+1;}
};
struct node{
	int id,v;
} s;
int c,n,m,d,q,w[N],k[505],len[N];
long long f[N],ans[N];
vector<node> e[505];
vector<node> b[N];
bitset<N> ok,vis; 
bool cmp(T x,T y){return x.x<y.x;}
void spfa(int x){
	for(int i=1;i<=m;++i) f[i]=INF;
	f[x]=0;
	Q<int> q;q.push(x);
	while(!q.empty()){
		int x=q.front();
		q.pop();ok[x]=0;
		for(int i=0;i<len[x];++i){
			int ida=b[x][i].id;
			long long w=b[x][i].v+f[x],fx;
			for(int j=0;j<k[ida];++j){
				int v=e[ida][j].id;
				fx=w+e[ida][j].v;
				if(f[v]>fx){
					f[v]=fx;
					if(!ok[v]){
						ok[v]=1;
						q.push(v);
					}
				}
			}
		}
	}
}
int read(){
	int num=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num;
}
void print(long long x){
	char c[18];
	int num=0;
	while(x){
		c[++num]=x%10|48;
		x/=10;
	}
	for(int i=num;i>=1;--i) putchar(c[i]);
	puts("");
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i) w[i]=read();
	for(int i=1;i<=n;++i){
		k[i]=read(),e[i].reserve(k[i]),s.id=i;
		for(int j=0;j<k[i];++j){
			int aa=read(),tt=read();s.v=tt;
			b[aa].push_back(s);
			++len[aa];
			e[i][j].id=aa;
			e[i][j].v=tt;
		}
	}
	for(int i=1;i<=q;++i){
		qu[i].x=read(),qu[i].y=read(),qu[i].id=i;
		if(qu[i].x>qu[i].y) swap(qu[i].x,qu[i].y);
	} 
	sort(qu+1,qu+1+q,cmp);
	for(int i=1;i<=q;++i){
		if(!vis[qu[i].x]) spfa(qu[i].x),vis[qu[i].x]=1;
		ans[qu[i].id]=f[qu[i].y]+w[qu[i].x]+w[qu[i].y];
	}
	for(int i=1;i<=q;++i) print(ans[i]);
	return 0;
}
