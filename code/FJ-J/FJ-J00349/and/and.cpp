#include<bits/stdc++.h>
using namespace std;
int ans=-2.14e9;
const int maxn=2e5+5;
int v[maxn],n,m;
inline int rea(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			f=-1;
		}c=getchar();
	}while(c<='9'&&c>='0'){
		x*=10;x+=c-'0';
		c=getchar();
	}return x*f;
}inline bool cmp(int a,int b){return a>b;}
void dfs(int d,int aa,int x){
	if(d==m){ans=max(ans,aa);return;}
	if(x+m-d>n)return;
	if(aa<ans)return;
	for(int i=x+1;i<=n;i++){
		dfs(d+1,aa&v[i],i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	n=rea(),m=rea();
	for(int i=1;i<=n;++i)v[i]=rea();
	stable_sort(v+1,v+n+1,cmp);
	for(int i=1;i<=n;i++)dfs(1,v[i],i);
	cout<<ans;
	return 0;
}
