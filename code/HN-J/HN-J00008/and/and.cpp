#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
long long n,m,a[N],mx;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long d=a[n];
	for(long long i=n-1;i>n-m;i--){
		d&=a[i];
	}
	cout<<d;
	return 0;
}
