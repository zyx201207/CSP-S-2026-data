//3
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=0;
void dfs(int x,long long sum,int num){
	if(num==m){
		ans=max(ans,sum);
		return ;
	}
	if(x>n){
		return ;
	}
	dfs(x+1,sum&a[x],num+1);
	dfs(x+1,sum,num);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,(1<<31)-1,0);
	cout<<ans;
	return 0;
}
