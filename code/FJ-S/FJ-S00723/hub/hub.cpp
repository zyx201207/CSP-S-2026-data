#include <bits/stdc++.h>
using namespace std;
typedef long long dll;
const int maxn=1e5+1;
const int maxbign=3e5+1;
 int c,t,n,q;
vector<int> g[maxn];

inline dll read(){
	dll x=0; bool neg=false;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') neg=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return (neg? -x:x);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		for(int i=1,u,v;i<n;++i){
			scanf("%d%d",u,v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		unsigned int ans;
		printf("%d",ans);
	}
	return 0;
}
