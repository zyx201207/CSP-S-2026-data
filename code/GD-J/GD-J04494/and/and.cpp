#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define gc getchar
int read(){
	int x=0,c=gc();
	while(c<'0'&&c>'9'){
		if(c==EOF)return 0;
		c=gc();
	}while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=gc();
	} return x;
}
int n,m;
ll a[200002],ans;
void dfs(int idx,int cnt,ll sum){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}if(idx>n)return;
	if(cnt+n-idx+1<cnt)return;
	dfs(idx+1,cnt,sum);
	dfs(idx+1,cnt+1,sum&a[idx]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	dfs(1,0,LLONG_MAX);
	printf("%lld",ans);
	return 0;
}
