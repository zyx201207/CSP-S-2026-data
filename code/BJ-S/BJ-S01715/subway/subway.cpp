#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10,Q=1e5+10,inf=LLONG_MAX;
int c,n,m,d,q,a[N+(M<<1)],kou[M],cnt;
struct edge{
	int to,w;
};
vector<edge> v[N+(M<<1)];
struct node{
	int u,dis;
	friend bool operator >(const node x,const node y){
		return x.dis>y.dis;
	}
};
priority_queue<node,vector<node>,greater<node> > qu;
inline void dj(int x){
	a[x]=0;
	qu.push({x,0});
	while(!qu.empty()){
		int u=qu.top().u;
		qu.pop();
		for(edge i:v[u]){
			int to=i.to;
			if(a[u]+i.w<a[to]){
				a[to]=a[u]+i.w;
				qu.push({to,a[to]});
			}
		}
	}
}
struct ques{
	int x1,y1,id,ans;
}qe[Q];
inline bool cmp1(ques x,ques y){
	return x.x1<y.x1;
}
inline bool cmp2(ques x,ques y){
	return x.id<y.id;
}
inline int read(){
    char ch=0;
    int x=0;
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    int x,y,z;
    for(int i=1;i<=m;i++)
		kou[i]=read();
	cnt=m;
	for(int i=1;i<=n;i++){
		x=read();
		cnt++;
		for(int j=1;j<=x;j++){
			y=read();
			z=read();
			v[y].push_back({cnt,z});
			v[cnt].push_back({y,z});
		}
	}
	
	for(int i=1;i<=q;i++){
		qe[i].x1=read();
		qe[i].y1=read();
		if(qe[i].x1>qe[i].y1)
			swap(qe[i].x1,qe[i].y1);
		qe[i].id=i;
	}
	
	sort(qe+1,qe+q+1,cmp1);
	
	for(int i=1;i<=q;i++){
		if(qe[i].x1!=qe[i-1].x1){
			for(int i=1;i<=cnt;i++)
				a[i]=inf;
			dj(qe[i].x1);
		}
		qe[i].ans=a[qe[i].y1]+kou[qe[i].x1]+kou[qe[i].y1];
	}
	sort(qe+1,qe+q+1,cmp2);
	for(int i=1;i<=q;i++){
		write(qe[i].ans);
		putchar('\n');
	}
	
}
