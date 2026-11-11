#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long ans=0;
bool cmp(long long x,long long y){
	return (x&1267650600228229401496703205375)>(y&1267650600228229401496703205375);
}
void dfs(long long now,long long sy,long long dq){
	if(sy==m){
		ans=max(dq,ans);
		return;	
	}
	for(long long i=now+1;i<=n;i++){
		dfs(i,sy+1,dq&a[i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=1073741823;
	if(n<=10000){
		dfs(0,0,1073741823);
	}else{
		sort(a+1,a+n+1,cmp);
		ans=1073741823;
		for(long long i=1;i<=m;i++){
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}