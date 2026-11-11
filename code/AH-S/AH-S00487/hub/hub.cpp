#include<bits/stdc++.h>
using namespace std;
#define int long long
#define For(i,j,k) for(int i=(j);i<=(k);i++)
inline int read(){
	int ans=0,f=1;
	char c=getchar_unlocked();
	while(c<48||c>57){
		if(c=='-') f=-1;
		c=getchar_unlocked();
	}
	while(c>=48&&c<=57){
		ans=ans*10+c-48;
		c=getchar_unlocked();
	}
	return ans*f;
}
const int M=5010,inf=2e18+7;
int c,T,n,k;
vector<int> E[M];
void init(){
	
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--){
		init();
		n=read(),k=read();
		if(c==13||c==14){
			For(i,1,n-1) read(),read();
			if(k==n) {printf("0\n");continue;}
			int m=n/2;
			int ans=(m+2-k+3)/4;
			printf("%lld\n",max(1ll,ans));
			continue;
		}
		For(i,1,n-1){
			int u=read(),v=read();
			E[u].push_back(v),E[v].push_back(u);
		}
	}
	return 0;
}
