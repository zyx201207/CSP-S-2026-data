#include<bits/stdc++.h>
using namespace std;
long long a[200000];
string c[200000];
long long n,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	for(long long j=1;j<=a[j]/2;j++){
		if(a[j]!=a[n-j]) cnt++;
	}
	cout<<cnt;
	return 0;
}
