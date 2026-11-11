#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=1;
	cin>>n>>m;
	long long a[n],b[n]{};
	for(long long i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	b[0]=a[0];
	for(long long i=1;i<n;i++){
		long long t=m;
		b[i]=a[i]+b[i-1];
		if(a[i]*i-b[i-1]<=t) s=i+1;
		else break;
	}
	cout<<s;
	return 0;
}
