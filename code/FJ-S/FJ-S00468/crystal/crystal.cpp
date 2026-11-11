#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],s[500005],sum,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
 	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
 	}
	for(int i=n;i>=1;i--){
		sum=a[i]*i-s[i];
		long long l=1,r=i-1;
		while(l<r){
			int mid=(l+r)>>1;
			if((sum-(a[i]*(mid-1)-s[mid-1]))<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(i-l+1,ans);
	}
	cout<<ans;
	return 0;
}
