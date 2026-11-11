#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000000];
int n,m;
int pan(int mid){
	int sum1=0;
	for(int i=1;i<=mid;i++){
		sum1=sum1+a[mid]-a[i];
	}
	if(sum1<=m) return true;
	else return false;
}
int pan2(int mid){
	int sum2=0;
	for(int i=1;i<=mid;i++){
		sum2=sum2+a[1]-a[mid];
	}
	if(sum2<=m) return true;
	else return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	if(a[2]-a[1]<=a[n]-a[n-1]){
		int l=0,r=n;
		int mid;
		int ans=-1e12;
		while(l<=r){
			mid=(l+r)/2;
			if(pan(mid)==true){
				ans=max(ans,mid);
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		cout<<ans;
	}
	else{
		sort(a+1,a+1+n,greater<int>() );
		int l=0,r=n;
		int mid;
		int ans=-1e12;
		while(l<=r){
			mid=(l+r)/2;
			if(pan2(mid)==true){
				ans=max(mid,ans);
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		cout<<ans;
	}
	
	return 0;
}
