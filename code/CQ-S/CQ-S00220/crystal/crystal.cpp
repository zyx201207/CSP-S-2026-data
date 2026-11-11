#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int max1=-1;
	for(int i=1;i<=n;i++){
		int left=1,right=i,mid=0;
		int ans1=0,ans2=0;
		while(left<right){
			mid=(left+right)/2;
			ans1=a[i]*(i-mid+1);
			ans2=s[i]-s[mid-1];
			if(ans1-ans2<=m){
				right=mid;
			}else{
				left=mid+1;
			}
		}
		max1=max(max1,i-left+1);
	}
	cout<<max1;
	return 0;
}
