#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans=0;
void dfs(int st,int x,int cnt){
	if(x==0){
		return;
	}
	if(cnt==m){
		ans=max(ans,x);
		return;
	}
	if(cnt>m){
		return;
	}
	for(int i=st+1;i<n;i++){
//		if(x&a[i]!=0){
		dfs(i,x&a[i],cnt+1);
//		}
		
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n-m;i++){
		dfs(i,a[i],1);
	}
	cout<<ans;
	//±©Á¦³öÆæ¼££¡£¡£¡£¡£¡ 
	return 0;
} 
