#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,c;
int a[10000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	c=m;
	for(int i=n;i>=2;i--){
		c=a[n]-a[n-1];
		if(i>=0){
			sum++;
		}else{
			c+=a[n]-a[n-1];
			break;
		}
	}
	m=1;
	for(int i=n;i>1;i--){
		c+=sum*a[i]-a[i-1]+a[i-sum];
		if(c>m){
			if(i>=a[i-1]-a[i-1-sum]){
				sum++;
				c-=a[i-1]-a[i-1-sum];
			}
			m=1;
		}
	}
	cout<<sum-4;
	return 0;
}
