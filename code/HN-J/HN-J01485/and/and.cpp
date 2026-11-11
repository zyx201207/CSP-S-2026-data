#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long mp[200009];
long long n,m,mx;
void dfs(long long idx,long long cnt,long long yh){
	if(idx+cnt-1<m)return;
	if(cnt==m){
		mx=max(mx,yh);
		return;
	}
	if(idx==1){
			return;
	}
	dfs(idx-1,cnt,yh);//no
	dfs(idx-1,cnt+1,yh&a[idx]);//yes
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long ml=0;
	for(int i=n;i>=m;i--){
		mx=0;
		dfs(i-1,1,a[i]);
		long long l=mx;
		ml=max(ml,l);
	}
	if(ml==0)cout<<1;
	else cout<<ml;
	return 0;
} 
