#include<bits/stdc++.h>
using namespace std;
long long n,m,a[520000],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum+=i*(a[i+1]-a[i]);
		if(sum>m){
			cout<<i;
			return 0;
		}
	}
	cout<<n;
	return 0;
} 
