// GZ-S00399 µËÍûÔÆ 
#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		a[i]=a[i+1]-a[i];
	}
	long long ma=0;
	for(int i=1;i<=n-1;i++){
		long long t=i;
		long long s=0;
		while(s<=m&&t<n){
			s+=a[t];
			t++;
		}
		ma=max(ma,t-i);
	}
	cout<<ma;
}
