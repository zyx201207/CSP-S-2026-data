#include<bits/stdc++.h>
using namespace std;
#define int long long
int pre[501010],a[501010],n,m;
bool check(int x){
	for(int i=x;i<=n;i++){
		int presm=pre[i]-pre[i-x-1];
		int less=x*a[i]-presm;
		if(less<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=1,r=n;
	int ans=1;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid,l=mid+1;
		}else r=mid-1;
	}
	if(check(l))cout<<l<<"\n";
	else cout<<ans<<"\n";
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
accept!!!
*/
