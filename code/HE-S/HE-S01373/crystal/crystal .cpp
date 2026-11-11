#include <bits/stdc++.h>
using namespace std;
long long n,m,t2=0;
int fac1(long long a,long long z){
	long long i=z;
	while(a>=i){
		a-=i;
		i+=z;
	}
	return i/z-1;
}
int main(){
	freoprn("crystal.in","r",stdin);
	freoprn("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	vector<long long> a(n);
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	long long z=a[1]-a[0];
	for(long long i=1;i<n;i++){
		if(a[i]-a[i-1]==z) t2++;
	}
	if(t2==n-1) cout<<fac1(m,z)+1;
	return 0;
}
