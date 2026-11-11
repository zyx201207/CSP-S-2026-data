#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,n;
ll a[500005],sum=1;
ll b[500005],c[500005];
ll i,j;
bool A=0,B=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			A=1;
		}
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			B=1;
		}
		b[i]=b[i-1]+a[i]-a[i-1];
		c[i]=b[i]+c[i-1];
	}
	if(B==0||A==0){
		for(i=1;i<=n;i++){
			if(c[i]>m){
				break;
			}
		}
		if(i<n)
		cout<<i-1;
		else cout<<n;
	}
	else{
		sort(a+1,a+n+1);
		for(i=1;i<=n-sum;i++){
			ll sum1=1;
			ll m1=m;
			j=i;
			while(m1-(a[j+1]-a[j])*sum1>=0&&j<n){
				j++;
				m1-=(a[j]-a[j-1])*sum1;
				sum1++;
			}
			sum=max(sum,sum1);
		}
		cout<<sum;
	}
	return 0;
}

