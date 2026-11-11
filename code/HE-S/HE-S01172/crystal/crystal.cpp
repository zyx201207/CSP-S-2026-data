#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,a[500010],s[500010];
bool ck(int x){
	for(int i=x;i<=n;i++){
//		if(x==3)cout<<i<<" "<<a[i]<<" "<<s[i]-s[i-x]<<"\n";
		if(a[i]*x-(s[i]-s[i-x])<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ck(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
