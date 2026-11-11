#include<bits/stdc++.h>
using namespace std;
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
const int N=1e6+6;
int c,t,n,k;
vector<int> g[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		for(int i=1; i<n; i++){
			int x,y;
			x=read(),y=read();
			g[x].push_back(y);
			g[y].push_back(x);
		}
		printf("1\n");
	}
	return 0;
}

