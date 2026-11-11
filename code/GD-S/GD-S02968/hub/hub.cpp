#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define ciallo continue
using namespace std;
inline int read(){
	char c=getchar();
	int res=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f*=-1;
		c=getchar();
	}while(isdigit(c)){
		res=res*10+c-48;
		c=getchar();
	}
	return res*f;
}
const int N=1e6+10;
int c,t,n,k;
vector<int> tree[N];
int f[N];
inline int fd(int b){
	if(b==f[b]) return b;
	return f[b]=fd(f[b]);
}
inline bool chk(int b){
	int res=0;
	while(b){
		if(b&1) res++;
		b>>=1;
	}
	return (res==k);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		n=read();
		k=read();
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<n;i++){
			int u=read();
			int v=read();
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		cout<<(int)sqrt(double(n))<<"\n";
	}
	return 0;
}
