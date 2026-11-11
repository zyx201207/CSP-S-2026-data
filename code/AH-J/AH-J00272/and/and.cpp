#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long ans=0;
bool cmp(int a,int b){
	return a>b;
}
bool u[200005];
void dfs(int s,long long h){
	if(s==m){
		ans=max(ans,h);
		return;
	}
	for(int i=1;i<=n;i++){
		if(u[i]==0){
			u[i]=1;
			dfs(s+1,h&a[i]);
			u[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	if(n==m){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
		return 0;
	}	
	for(int i=1;i<=n;i++){
		u[i]=1;
		dfs(1,a[i]);
		u[i]=0;
	}
	cout<<ans<<endl;
}
