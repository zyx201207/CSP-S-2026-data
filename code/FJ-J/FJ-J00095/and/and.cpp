#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[300000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n);
	cout<<a[2];
	return 0;
}
