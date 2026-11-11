#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long c[500005],c2[500005];
long long sum[500005];
long long m;
bool check(int j,int i){
	return sum[j]-sum[i-1]-(i-1)*(c2[j]-c2[i-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		c2[i]=c2[i-1]+c[i];
	}
	for(long long i=2;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*c[i];
	}
	int out=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(i,mid)){
				ans=mid;
				r=mid-1;
			}
			else {
				l=mid+1;
			}
		}
		out=max(out,i-ans+1);
	} 
	cout<<out; 
	return 0;
} 
