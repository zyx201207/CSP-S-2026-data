//GZ-S00233 遵义市第四中学 毛俊程 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=5e5+5;
ll n,m,a[MAXN],s[MAXN];
int ans;
bool check(int x){
	for(int i=n;i>=x;i--){
		ll t=a[i]*x-(s[i]-s[i-x]);
		if(t<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

