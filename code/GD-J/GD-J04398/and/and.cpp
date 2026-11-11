#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=0,maxx=1,sss=1;
void dfs(long long i,long long x,long long sum){
	if(x==m){
		ans=max(ans,sum);
	} 
	if(i>n) return ;
	if(n-i+1<m-x) return ;
	dfs(i+1,x+1,sum&a[i]);
	dfs(i+1,x,sum);
	
}
int main(){
	freopen("and.in" , "r" , stdin );
	freopen("and.out" , "w" , stdout );
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=30;i++){
		sss*=2;
		maxx+=sss;
	}
	dfs(1,0,maxx);
	cout<<ans;
	return 0;
}
