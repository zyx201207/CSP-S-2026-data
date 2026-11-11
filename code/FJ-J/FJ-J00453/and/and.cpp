#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200005],n,m,ans;
bool cmp(int a,int b){
	return a>b;
}void dfs(int sum,int time,int id){
	if(time==m-1){
		for(int i=id+1;i<=n;i++){
			ans=max(ans,sum&a[i]);
		}return ;
	}
	if(time==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=id+1;i<=n;i++){
		dfs(sum&a[i],time+1,i);
	}return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n,cmp);
	if(n>2000){
		ans=a[1];
		for(int i=2;i<=m;i++)ans&=a[i];
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++)dfs(a[i],1,i);
		cout<<ans;
	}
	return 0;
} 
