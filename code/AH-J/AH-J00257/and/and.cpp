#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,ans=0;
void dfs(int num,int y,int cnt){
	if(y==0){
		ans=max(ans,cnt);
		return;
	}
	for(int i=num+1;i<=n-y+1;i++){
		dfs(i,y-1,(cnt&a[i]));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n-m+1;i++)dfs(i,m-1,a[i]);
	cout<<ans;
}
