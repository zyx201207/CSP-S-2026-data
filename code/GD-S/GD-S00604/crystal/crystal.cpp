#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N=5e5+5;
long long a[N]; 
long long arr[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)arr[i]=a[i]+arr[i-1];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int mid=(l+r)/2;
		while(l<r){
			mid=(l+r)/2;
			int t=arr[i-1]-arr[mid-1];
			if((i-mid)*a[i]-t<=m)	r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
