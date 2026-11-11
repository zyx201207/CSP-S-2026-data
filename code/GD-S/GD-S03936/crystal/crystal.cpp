#include<bits/stdc++.h>
using namespace std;
long long a[500010],ad[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ma=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		ad[i]=ad[i-1]+(i-1)*(a[i]-a[i-1]);
		if(ad[i]<=m){
			ma=max(ma,i);
			continue;
		}
		long long l=1,r=i,mid,ans=0;
		while(l<=r){
			mid=(r-l)/2+l;
			if(ad[i]-ad[mid]-(mid-1)*(a[i]-a[mid])<=m){
				r=mid-1;
				ans=mid;
			}
			else{
				l=mid+1;
			}
		}
		ma=max(ma,i-ans+1);
	}
	cout<<ma<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
