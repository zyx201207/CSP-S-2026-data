#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,b=-1;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		if(i*a[i]-sum[i]<=m)b=max(b,i);
		else{
			long long c=i*a[i]-sum[i];
			int l=1,r=i;
			while(l<r){
				int mid=(l+r)/2;
				if(c<=sum[mid]){
					r=mid;
				}
				else{
					l=mid+1;
				}
			}
			b=max(b,i-l+1);
		}
	}
	cout<<b;
	return 0;
}
