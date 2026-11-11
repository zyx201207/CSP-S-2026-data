#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=5e5+7;
ll n,m;
ll a[N];
ll sum[N];
bool check(ll mid){
	bool ok=false;
	for(int l=1;l+mid-1<=n;l++){
		int r=l+mid-1;
		ll k=sum[r]-sum[l-1]+m;
//		cout<<"k="<<k<<'\n';
		ll kr=k/mid;
//		cout<<"mid="<<mid<<'\n';
//		cout<<"kr="<<k<<'\n';
//		cout<<"a[r]="<<a[r]<<'\n';
		if(kr>=a[r]){
			ok=true;
//			for(int i=l;i<=r;i++){
//				cout<<a[i]<<' ';
//			}
//			cout<<'\n';
		}
	}
	if(ok){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	} 
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
//		cout<<"mid="<<mid<<'\n';
		if(check(mid)){
			l=mid+1;
//			cout<<'l'<<'='<<l<<'\n';
		} else{
			r=mid-1;
//			cout<<"r="<<r<<'\n';
		}
	}
	
	cout<<r<<'\n';
//	if(ok){
//		cout<<r<<'\n';
//	}else{
//		cout<<r-1<<'\n';
//	}
	return 0;
}
