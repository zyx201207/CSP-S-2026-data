#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		a[i]=a[i+1]-a[i];
	}
	for(int i=2;i<n;i++){
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>m){
			cout<<i;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
