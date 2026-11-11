#include<bits/stdc++.h>
using namespace std;
int a[200005]={},n,m;
int dfs(int choose,int sum,int from){
	if(from==n+1&&choose<m) return -1;
	int x=dfs(choose+1,sum&a[from],from+1);
	int y=dfs(choose+2,sum&a[from],from+2);
	return max(x,y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<dfs(0,2147483647,0);
	return 0;
}
