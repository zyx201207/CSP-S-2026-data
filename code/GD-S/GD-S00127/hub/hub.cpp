#include<bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
#define fi first
#define se second
#define eb emplace_back
inline int read(){
	int t=1,c=getchar(),res=0;
	for(;!isdigit(c);c=getchar())if(c=='-')t=-t;
	for(;isdigit(c);c=getchar())res=(res<<1)+(res<<3),res+=c^48;
	return res*t;
}
inline void write(int num){
	if(num<0)putchar('-'),num=-num;
	if(num>9)write(num/10);
	putchar('0'+num%10);
	return;
}
const int N=1e6;
vector<int>edge[N+7];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		int n=read(),k=read();
		for(int i=1;i<=n;i++){
			edge[i].clear();
		}
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			edge[u].eb(v);
			edge[v].eb(u);
		}
		if(c==13||c==14){
			int m=(n-1)/2;
			if(k==n)write(0);
			else if(k>=m)write(1);
			else write((int)(ceil(m/k)+2)/2);
		}
	}
	return 0;
}
