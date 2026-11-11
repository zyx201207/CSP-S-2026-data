#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],sum,b[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]*i<=b[i]+m){
			sum++;
		}
		else{
			cout<<sum;
			return 0;
		}
	}
	cout<<sum;
	return 0;
}
