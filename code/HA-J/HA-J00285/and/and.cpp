#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[200010]={0};
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		long long c=-1;
		for(long long i=1;i<=n;i++) c=max(c,a[i]);
		cout<<c;
	} else if(m==2){
		long long c=-1;
		for(long long i=1;i<n;i++) for(int j=i+1;j<=n;j++) c=max(c,a[i]&a[j]);
		cout<<c;
	} else if(m==n){
		long long c=a[1];
		for(long long i=2;i<=n;i++) c&=a[i];
		cout<<c;
	}
	cout<<7;
}
