#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,f[20005][20005];
int read(){
	char c=getchar();
	int s=0,f=1;
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
}
void dfs(int x,int s,int sum){
	if(x>n+1) return;
	if(s>m+1) return;
	if(s==m+1){
		f[x][s]=max(f[x][s],sum);
		ans=max(ans,sum);
		return;
	}
	if(sum<f[x][s]) return;
	dfs(x+1,s+1,sum&a[x]);
	dfs(x+1,s,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	dfs(1,1,1073741823);
	cout<<ans<<endl;
}
