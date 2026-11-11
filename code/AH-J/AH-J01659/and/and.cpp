#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=0;
void dfs(int r,int k,int res){
	if(k>=m){
		ans=max(ans,res);
		return;
	}
	if(r>n) return;
	dfs(r+1,1,a[r+1]);
	for(int i=r+1;i<=n;i++){
		dfs(i,k+1,res&a[i]);
	}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);  
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
	}
	dfs(1,1,a[1]);
	printf("%d",ans);
    return 0;
}
