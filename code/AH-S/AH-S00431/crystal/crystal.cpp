#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],t[500009],sum=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) t[i]=t[i-1]+a[i];
	for(int i=1;i<n;i++){
		long long L=i+1,R=n,ans;
		while(L<=R){
			long long mid=(L+R)/2;
			if((mid-i)*a[mid]-t[mid-1]<=m-t[i-1]) ans=mid-i+1,L=mid+1;
			else R=mid-1;
		}
		sum=max(ans,sum);
	}
	cout<<sum;return 0;
}
