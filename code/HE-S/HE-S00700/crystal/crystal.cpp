#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],sum[N];
int n,m;
int d[N];
bool check(int mid){
	for(int i=1;i<=n-mid;i++){
		//i~i+mid，能不能构成
		int summ=0,tt=1;
		for(int j=i;j<=i+mid;j++) summ+=a[i+mid]-a[j];
		if(summ<=m) return true;
	}
	return false;
} 
bool check2(int mid){
	int summ=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=a[mid]) break;
		summ+=(a[mid]-a[i]); 
	}
	if(summ<=m) return true;
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int s=0,ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	int l=1,r=n;
	if(m<5050){
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}}else{
	while(l<r){
		int mid=(l+r+1)/2;
		if(check2(mid)) l=mid;
		else r=mid-1;
	}
	l--;
	}
	cout<<l+1;
	return 0;
} 
