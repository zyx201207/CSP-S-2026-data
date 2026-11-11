#include <bits/stdc++.h>
using namespace std;

int n,m,maxx;
long long a[100005];
int c[100005];

inline void dfs(int i,int cnt,int pre){
	if(i>n){
		if(cnt==m){
			int ans=a[pre];
			for(int j=1;j<=n;j++){
				if(c[j]){
					ans=ans&a[j];
					
				}
			}
			maxx=max(ans,maxx);
		}
		return;
	}
	c[i]=0;
	dfs(i+1,cnt,pre);
	if(cnt<m){
		c[i]=1;
		dfs(i+1,cnt+1,i);
	}
}


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dfs(1,0,0);
	
	printf("%d",maxx);
}
