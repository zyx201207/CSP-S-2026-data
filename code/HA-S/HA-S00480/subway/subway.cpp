#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long n,m;
	long long a[10001];
	cin>>a[n];
	if(a[n]%2==0){
		cout<<a[n]-n;
		cout<<a[n-2]*n;
	}
	return 0;
}
