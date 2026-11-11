#include<bits/stdc++.h>
using namespace std;
long a[100086];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long s2=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		s2=a[i]&s2;
	}
	cout<<s2;
}
