#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read(){ int x=0,f=1;char ch=getchar();while(!isdigit(ch)){ if(ch=='-')f=-1;ch=getchar(); }while(isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48);ch=getchar(); }return x*f; }
inline void write(int x){ if(x<0){ putchar('-');x=-x; }char c[23];int cnt=0;do{ c[++cnt]=x%10|48;x/=10; }while(x);while(cnt){ putchar(c[cnt--]); }putchar(' '); }
const int N=200005;
int n,a[N],T,c,k;
vector<int>e[N];
signed main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	c=read();T=read();
	while(T--){
		n=read();k=read();
		if(c==13||c==14){
			if(k>n/2)write((k!=n));
			else write((n/2+1-k-1)/(k+1)+2);
			puts("");
		}
		for(int i=1;i<n;i++){
			int u=read(),v=read();e[u].emplace_back(v);e[v].emplace_back(u);
		}
		for(int i=1;i<=n;i++)e[i].clear();
	}
	return 0;
}
