#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500005]={};
long long s[500005]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long mx=LLONG_MIN+1;
	for(long long i=0;i<n;i++){
		for(long long j=i;j<n;j++){
			if((s[j]-s[i]+a[i]+m)/(j-i+1)>=a[j]){
				mx=max(mx,j-i+1);
			}
		}
	}
	cout<<mx;
	return 0;
}

