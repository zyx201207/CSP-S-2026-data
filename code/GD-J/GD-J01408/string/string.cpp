#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
long long a[200005];
char c[200005];
void dfs(int l,int r){
	if(l>=r) return;
	if(c[l]!=c[r]){
		ans+=min(a[l],a[r]);
	}
	if(a[l]==a[r]){
		dfs(l+1,r-1);
	}else if(a[l]<a[r]){
		a[r]-=a[l];
		dfs(l+1,r); 
	}else{
		a[l]-=a[r];
		dfs(l,r-1);
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
	dfs(1,n);
	printf("%lld",ans);
	return 0;
}
