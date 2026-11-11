#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long pre[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		int l=1,r=i;
		int tans=0;
		while(l<=r){
			int mid=(l+r)/2;
			long long t=mid*a[i]-(pre[i]-pre[i-mid]);
			if(t<=m){
				tans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,tans);
	}
	cout<<ans;
	return 0;
} 
