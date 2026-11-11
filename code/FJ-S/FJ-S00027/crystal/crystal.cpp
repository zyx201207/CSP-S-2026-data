#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
long long qz[500005];
long long sum(int l,int r){
	return qz[r]-qz[l-1];
}
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		int l=i,r=i+x-1;
		if((a[r]*x-sum(l,r))<=m)return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)qz[i]=qz[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}
