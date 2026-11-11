#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],c;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		if((s[i]+m)/i==a[i]){
			c=i;
		}
	}
	cout<<c;
	return 0;
}
