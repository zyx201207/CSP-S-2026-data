#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],d[500005],q[500005],flag=0;
long long n;
int main(){	
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long sum=0;
	long long ans=1;
	d[1]=0;
	for (int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	for (int i=1;i<=n;i++)
		q[i]=q[i-1]+d[i]; 
    long long l=1;
	for (long long r=1;r<=n;r++){
		if (sum+(r-l)*d[r]<=m){
			sum+=(r-l)*d[r];
			if (r==n)
				flag=1;
		}
		else {
			sum+=(r-l)*d[r];
			if (r-l>ans){
				ans=r-l;
			}
			while (sum-(q[r]-q[l])>m){
				sum-=q[r]-q[l];
				l++; 
			}
			sum-=(q[r]-q[l]);	
			l++;
		}
	}
	if (flag==1){
		if (n-l+1>ans){
			ans=n-l+1;
		}
	}
    cout<<ans;
	return 0;
}
