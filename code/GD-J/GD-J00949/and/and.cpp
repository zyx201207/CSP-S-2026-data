#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200003];
int dfs(int i,int h,int num){
	if(i>n||num==m) return h;
	if(num==0){
		return max(dfs(i+1,a[i],num+1),dfs(i+1,h,num));
	}
	else return max(dfs(i+1,h&a[i],num+1),dfs(i+1,h,num));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,0,0);
	return 0;
}
