#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],m;
long long dfs(int x,int j){
	if((m-j)>(x+1)){
		return 0;
	}
	if(x==0){
		if(j==m-1) return a[0];
		else return 0;
	}
	if(j==m-1){
		return max(a[x],dfs(x-1,j));
	}
	return max((a[x]&dfs(x-1,j+1)),dfs(x-1,j));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<dfs(n-1,0);
	return 0;
} 
