#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m;
long long a[500005],s[500005];
long long maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal2.in","r",stdin);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){//选择a[i]作为变化值 
		long long l=1,r=i;
		while(l<=r){
			long long mid=(l+r)/2;
			if(((long long)(a[i]*mid)-(long long)(s[i]-s[i-mid]))<=m){
				l=mid+1;
			}
			else r=mid-1;
		}
		maxn=max(r,maxn);
//		cout<<i<<" "<<r<<endl;
	}
//	cout<<pos<<" "<<a[pos]<<endl;
//	cout<<(long long)(a[pos]*maxn)<<" "<<(long long)(s[pos]-s[pos-maxn])<<" "<<((long long)(a[pos]*maxn)-(long long)(s[pos]-s[pos-maxn]))<<endl;
//	cout<<m<<endl;
	cout<<maxn;
	return 0;
}
/*
10 8
-12 -3 -3 -3 -1 12 13 15 16 19
4
*/

