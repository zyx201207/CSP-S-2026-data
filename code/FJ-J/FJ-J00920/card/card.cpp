#include<bits/stdc++.h>
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define int long long
#define IOimprove ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;T f=1;char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
vector<int> g[555555];
int n,m,a[555555],s[555555],vis[555555],ans[555555];
void dfs(int x){
	ans[x]=s[x];
	for(int i:g[x]){
		dfs(i);
		ans[x]+=ans[i];
	}
}
signed main(){
	file("card")
	read(n);read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
		s[a[i]]++;
	}
	for(int i=n;i>=1;i--){
		if(vis[a[i]])continue;
		vis[a[i]]=1;
		if(i!=n)g[a[i+1]].push_back(a[i]);
	}
	dfs(a[n]);
	for(int i=1;i<=m;i++){
		write(ans[i]);
		if(i!=m)putchar(' ');	
	}
	puts("");
	return 0;
}
