#include<bits/stdc++.h>
using namespace std;
int n,m,sum,ans;
int a[2000005],b[2000005];
void dfs(int x,int y){
	if(x>=m+1){
		sum=b[1];
		for(int i=2;i<=m;i++){
			sum=b[i]&sum;
		}
		ans=max(sum,ans);
		return ;
	}
	for(int i=y;i<=n;i++){
		b[x]=a[i];
		dfs(x+1,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=a[i]&ans;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
