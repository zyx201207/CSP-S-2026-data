#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
long long n,m,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s=a[n];
	for(int i=n;i>=n-m+1;i--){
		s&=a[i];
	}
	cout<<s;
	return 0;
} 
