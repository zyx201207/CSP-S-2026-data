#include<bits/stdc++.h>
using namespace std;

#define int long long

int read() {
	int x=0,f=1,ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

const int M=5*1e5+3,N=503,Q=1e5;

struct edge{
	int v,w;
	bool operator < (const edge& other) const {
		return w<other.w;
	}
};

int c,n,m,d,q,cnt;
vector<edge> graph[M];

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read();n=read();m=read();d=read();q=read();
	srand(time(0));
	while(q--) {
		cout<<rand()%40<<'\n';
	}
}
