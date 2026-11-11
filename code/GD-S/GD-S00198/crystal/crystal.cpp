#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],diff[500005],sum[500005],sumsum[500005],j,ls,l,r,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);//有序是一切的前置条件，否则后边推导的一切都不成立 
	for(int i=1;i<=n;i++){
		diff[i-1]=a[i]-a[i-1];
	}
	for(int i=n;i>=1;i--){
		sum[i]=sum[i+1]+diff[i];
		sumsum[i]=sumsum[i+1]+sum[i];
	}
	l=n-1;
	for(r=n;r>=1;r--){
		while(sumsum[l]-sum[r]*(r-l)-sumsum[r]<=m&&l>0){
			//cout<<l<<' '<<r<<' '<<sumsum[l]-sum[r]*(r-l)-sumsum[r]<<endl;
			l--;
		}
		ans=max(r-l,ans);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
