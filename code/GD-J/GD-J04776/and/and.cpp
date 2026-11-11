#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],p=1,ans=0;
string s[200005];
void dfs(int x,int sum,int num){
	if(sum==m){
		ans=max(ans,num);
		return ;
	}if(x>n)return ;
	dfs(x+1,sum+1,num&a[x]);
	dfs(x+1,sum,num);
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}p=INT_MAX;
	dfs(1,0,p);
	cout<<ans;
	return 0;
}
