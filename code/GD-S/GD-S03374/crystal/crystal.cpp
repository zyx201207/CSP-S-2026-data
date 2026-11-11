#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],s[N];
bool check(int mid){
	bool flag=0;
	for(int i=1;i<=n-mid+1;i++){
		if(s[i+mid-1]-s[i-1]+m>=mid*a[i+mid-1]){
			flag=1;
			break;
		}
	}
	return flag;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,mid,ans=1;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}

