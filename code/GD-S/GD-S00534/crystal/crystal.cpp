#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n;
ll m,a[N];
ll sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)/2;
			int tmp=a[i]*(i-mid)-(sum[i-1]-sum[mid-1]);
			if(tmp>m){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
