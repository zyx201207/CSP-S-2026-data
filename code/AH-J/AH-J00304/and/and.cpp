/*
CCF将对所有考生程序查重
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,mx=-0x3f3f3f3f,a[N];
void dfs(int pos,int cnt,int ans){
	if(cnt==m){
		mx=max(mx,ans);
		return ;
	}
	if(pos==n+1) return ;
	if(ans==0){
		dfs(pos+1,cnt+1,a[pos]);
	}else{
		dfs(pos+1,cnt+1,(ans&a[pos]));
	}
	dfs(pos+1,cnt,ans);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	if(n<=20){
		dfs(1,0,0);
		cout<<mx;
	}else{
		cout<<a[m];
	}
	return 0;
}
