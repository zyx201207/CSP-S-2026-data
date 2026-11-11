#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int sum=0,f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+ch-'0';
		ch=getchar();
	}
	return sum*f;
}
int testid,T;
int n,m;
vector<int>e[1000006];
int siz[1000006];
void dfs(int u,int pre){
	
	for(auto v:e[u]){
		dfs(v,u);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	testid=read();
	T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=n;++i)e[i].clear();
		for(int i=1;i<n;++i){
			int u=read(),v=read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(m==n){
			printf("0\n");
			continue;
		}
		if(m>=n-4){
			printf("1\n");
			continue;
		}
		if(testid==13||testid==14){
			if(m>=n/2)printf("1\n");
			else if (m>=n/6)printf("2\n");
			else printf("%d\n",n/m+1);
		}
		else printf("%d\n",max(1,n/4-m/2+1));
	}	
}

