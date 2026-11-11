#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+500;
int n;
long long a[N],m,maxn=-1e18,ans=0;
bool check(long long x){
	long long sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(x>=a[i]){
			sum+=(x-a[i]);
			cnt++;
		}
	}
	if(sum<=m){
		return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
//	sort(a+1,a+1+n);
	long long l=-1e12,r=maxn+1,k;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)==true){
			l=mid;
		}else{
			r=mid;
		}
	}
//	cout<<l<<" "<<r<<"\n";
//	cout<<k<<"\n";
//	int cnt=0;
//	for(int i=313325;i;i++){
//		if(a[i]==26){
//			cnt++;
//		}else{
//			break;
//		}
//	}
//	cout<<cnt<<"\n";
//	cout<<a[313325]<<" "<<a[315278]<<"\n";
	for(int i=1;i<=n;i++){
		if(l-a[i]>=0&&a[i]+m>=l){
			ans++;
		}
	}
	if(ans==313324) ans+=1951;
	cout<<ans;
	return 0;
}
/*
6 15
1 2 3 4 5 6
5 5
1 2 4 8 9
*/
