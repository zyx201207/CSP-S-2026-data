#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
ll a[1000000],qzh[1000000];
bool check(int x){
//	cout<<"abc"<<x<<'\n';
	for(int i=x;i<=n;i++){
//		cout<<i<<' '<<a[i]<<' '<<qzh[i]<<' '<<qzh[i-x]<<' '<<m<<'\n';
		if((x*a[i]-qzh[i]+qzh[i-x])<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		qzh[i]=a[i]+qzh[i-1];
	}
	ll l=0,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

