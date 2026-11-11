#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],ans;
void dfs(int i,long long nn,int last){
	if(i==m){
		ans=max(ans,nn);
		return ;
	}
	for(int j=last;j<=n;j++){
		if(i==0) dfs(i+1,a[j],j);
		else dfs(i+1,(nn&a[j]),j);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,1);
	cout<<ans;
	return 0;
}
