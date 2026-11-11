#include<bits/stdc++.h>
using namespace std;
long long n,m,sum1=0,k;
long long a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	k=a[n-1];
	m--;
	for(long long i=n-2;i>=0;i--){
		k=k&a[i];
		m--;
		if(m<=0){
			break;
		}
	}
	cout<<k;
	return 0;
} 
