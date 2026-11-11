#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,o,p,a[5000001],b[5000001],num=1,sum,la,c[5000001];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>o;
		a[i]=o;
	}
	sort(a+1,a+1+n);
	a[0]=0;
	for(int i=2;i<=n;++i){
		b[i]=a[i]-a[i-1];
	}
	la=2;o=1;
	for(int i=2;i<=n;++i){
	    p+=(b[i]*o);
		while(p>m){
			p-=(a[i]-a[la-1]);
			la+=1;
			num-=1;
			o-=1;
		}
		o+=1;
		num+=1;
		sum=max(num,sum);
	}
	cout<<sum;

	return 0;
 } 


