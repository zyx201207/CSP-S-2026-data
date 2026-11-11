#include<bits/stdc++.h>
using namespace std;
int n,maxx;
long long m,a[500005];
void dfs(int l,int r){
	int mid=(l+r)/2;
	if(l>r) return ; 
	int cnt=1,mn=m;
	for(int i=mid-1;i>=1;i--){
		if(mn>=a[mid]-a[i]){
			mn-=a[mid]-a[i];
			cnt++;
		}
		else break;
	}
	if(cnt>=maxx){
		maxx=cnt;
		dfs(mid+1,r);
	}
	else dfs(l,mid-1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,n);
	cout<<maxx;
	return 0;
}
