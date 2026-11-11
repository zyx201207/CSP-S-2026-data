#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10010000];
long long b,c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
sort(a,a+n,greater<int>());

c=(a[0]&a[1]);
for(long long i=2;i<m;i++){
c=(c&a[i]);
b=c;
	
}
cout<<c;
return 0;	
	
	
	
	
}
