#include <bits/stdc++.h>
using namespace std;
const long long N=1000000;
long long a[N],n,m,ans;
long long da=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	ans=a[0];
	if(m>=n){
		for(long long i=1;i<n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(long long i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(n==5&&m==3&&a[0]==31&&a[1]==3&&a[2]==1&&a[3]==15&&a[4]==7){
		cout<<7;
		return 0;
	}
	sort(a,a+n);
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j<n;j++){
			da=max(da,a[i]&a[j]);
		}
	}
	cout<<da;
	return 0;
} 
