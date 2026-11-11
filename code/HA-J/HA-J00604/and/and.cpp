#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			sum=max(a[i]&a[j],sum);
		}
	}
	cout<<sum;
	return 0;
}
