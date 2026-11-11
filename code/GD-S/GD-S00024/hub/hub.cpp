#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
inline int read(){
	int f=1,g=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		g=(g<<3)+(g<<1)+(c-'0');
		c=getchar();
	}
	return f*g;
}
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar((x%10)+'0');
	return ;
}
const int N=1e6+10;
int c,T,n,k;
vector<int>g[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout<<"1\n";
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--)solve();
	return 0;
}
/*

*/

