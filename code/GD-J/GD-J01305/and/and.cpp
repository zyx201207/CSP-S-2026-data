#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans,num[200010];
void dfs(int hm,int wh){
	if(hm==m+1){
		int v=num[1];
		for(int i=2;i<=m;i++) v=v&num[i];
		ans=max(ans,v); 
		return ;
	}
	for(int i=wh;i<n-(m-hm);i++){
		num[hm]=a[i];
		dfs(hm+1,i+1);
	} 
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	if(m==1) cout<<a[n-1];
	else if(m==n){
		for(int i=1;i<n;i++){
			a[i]=a[i]&a[i-1];
		}
		cout<<a[n-1];
	}
	else{
		dfs(1,0);
		cout<<ans;
	}
	return 0;
} 
