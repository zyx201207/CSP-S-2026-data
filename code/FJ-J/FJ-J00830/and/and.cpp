#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long ans,cnt,jr;
void dfs(int s,int sy){
	if(sy==0){
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=2;i++){
		if(i==2 || sy==n-s+1){
			jr++;
			if(jr==1) cnt=a[s];
			else cnt=cnt&a[s];
			dfs(s+1,sy-1);
			jr--; 
			cnt=cnt&a[s];
		}else{
			dfs(s+1,sy);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,m);
	cout<<ans;
	return 0;
}
