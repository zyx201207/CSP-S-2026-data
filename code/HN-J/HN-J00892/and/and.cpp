#include<bits/stdc++.h>
using namespace std;
int n,a[200010],m,mx;
int dfs(int x,int sum,int sumiszero){
	if(sumiszero==0){
		dfs(x+1,sum,0);
		dfs(x+1,sum+=a[x],1);
	}else{
		dfs(x+1,sum,1);
		dfs(x+1,sum&=a[x],1);
	}
	if(x==n){
		mx=max(sum,mx);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	dfs(0,0,0);
	cout<<mx;
	return 0;
}
