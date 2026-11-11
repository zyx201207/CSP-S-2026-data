#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100100]; 
//int dfs(int x,int y){
	
//} 
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	//dfs(1,0);
	int ans=0; 
	sort(a+1,a+1+n,cmp);
	ans=a[1]; 
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
} 

