#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long k=0,p=1,c=getchar();
	while(c!=EOF&&(c>'9'||c<'0')){
		if(c=='-')p*=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar(); 
	}
	return k*p;
}
void putt(long long x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)putt(x/10);
	putchar(x%10+'0');
}
const long long N=1e6+5;
vector<vector<long long> > adj;
long long dep[N];
void dfs(long long k,long long de){
	for(auto e:adj[k]){
		if(de+1<dep[e]){
			dep[e]=de+1;
			dfs(e,de+1);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c=read(),T=read();
	while(T--){
		long long n=read(),k=read();
		for(long long i=0;i<n-1;i++){
			long long v=read(),u=read();
			adj[v].push_back(u);
			adj[u].push_back(v);
			dep[i+1]=N;
		}
		dep[0]=0;
		dep[1]=1;
		dfs(1,1);
		sort(dep,dep+n);
		putt((dep[n-1]+dep[n-2]));
		putchar('\n');
	}
	return 0;
} 
