#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int sum,ans,max1=0;
int a[500005];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	max1=1;
	sum=0;
	for(int l=1,r=2; r<=n; r++) {
		if(sum+(r-l)*(a[r]-a[r-1])<=m){
			sum+=(r-l)*(a[r]-a[r-1]);
			max1=max(max1,r-l+1);
		}else{
			while(l<r&&sum+(r-l)*(a[r]-a[r-1])>m){
				sum-=a[r-1]-a[l];
				l++;
			}
			sum+=(r-l)*(a[r]-a[r-1]);
		}
	}
	cout<<max1<<endl;
	return 0;
}
