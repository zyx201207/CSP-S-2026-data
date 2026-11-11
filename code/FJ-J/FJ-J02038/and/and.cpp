#include<bits/stdc++.h>
using namespace std;
long long n,m,b;
long long a[201010];
long long er[1010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<a[n+1-m];
	return 0;
}
