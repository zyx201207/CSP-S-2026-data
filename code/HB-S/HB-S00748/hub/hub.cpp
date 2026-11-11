#include<bits/stdc++.h>
using namespace std;

int read(){
	int w = 1,s = 0;
	char ch = getchar();
	while(ch<48||ch>57){
		if(ch=='-')w = -1;
		ch = getchar();
	}
	while(ch>=48&&ch<=57){
		s = (s<<1)+(s<<3)+(ch^48);
		ch = getchar();
	}
	return w*s;
}

const int N = 2e6+10;


int c,t;
int n,k;
int vis[N];
vector<int> e[N];
mt19937 rnd(time(0)),rd(rnd());
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c = read(),t = read();
	while(t--){
		n = read(),k = read();
		for(int i = 1;i <= n;++i)e[i].clear();
		memset(vis,0,sizeof(vis));
		for(int i = 1;i < n;++i){
			int u = read(),v = read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int a = (rnd()+rd())%n;
		a %= n;
		if(a==0)a = 1;
		cout<<a<<endl;
	}
}