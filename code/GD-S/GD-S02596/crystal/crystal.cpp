#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long a[500001],b[500001];
	a[0]=0;
	b[0]=0;
	cin>>n>>m;
	for(int i=1;i<=4;i++){
		b[i]=1;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+((a[i]-a[i-1])*(i-1));
		if(b[i]>m){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;

	return 0;
}
