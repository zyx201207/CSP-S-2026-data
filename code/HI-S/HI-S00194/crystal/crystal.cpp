#include <bits/stdc++.h>
//#define long long ll;
using namespace std;
long long n,m,a[500005],sum[500005];
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i] = sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	int l = 1,r = n;
	while(l<=r){
		int mid = (l+r)/2;
		int sum = 1;
		for(int i = mid-1;i>=1;i--){
			if(m>=a[mid]-a[i]) sum++,m-=a[mid]-a[i];
			else continue;
		}
		
		l = mid+1;
		int nmid = 0;
		for(int i = mid+1;i<=n;i++){
			if(a[i]==a[mid]) nmid++;
				
			else break;
		}	
			if(sum+nmid>ans) ans = sum+nmid;
	
		else{
			r = mid-1;
		}
	}
	
	cout<<ans; 
}
