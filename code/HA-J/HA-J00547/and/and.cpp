#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxx=-10;
void dfs(int now,int ans,int num){
	if(ans==m){
		now=now&a[num];
		maxx=max(now,maxx);
		return ;
	}
	else{
		now=now&a[num];
		for(int i=num+1;i<=n;i++){
			dfs(now,ans+1,i);
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int an=a[i]&a[j];
				maxx=max(an,maxx);
			}
		}
	}
	if(m>=3){
		dfs(a[1],1,1);
	}
	cout<<maxx;
	return 0;
}
