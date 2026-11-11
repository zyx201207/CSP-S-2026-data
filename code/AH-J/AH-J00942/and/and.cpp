#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn,a[200010];
void dfs(long long id,long long cnt,long long ans){
	if(id==0||cnt==0){
		if(cnt==0){
			maxn=max(ans,maxn);
		}
		return;
	}
	if(ans<maxn&&ans!=-1)return;
	if(id==n){
		for(int i=id;i>0;i--){
			dfs(i,cnt-1,a[i]);
		}
	}else{
		for(int i=id;i>0;i--){
			dfs(i,cnt-1,a[i]&ans);
		}
		dfs(id--,cnt,ans);
	}
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1);
dfs(n,m,0);
cout<<maxn;
return 0;
}
