#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b = a[1] & a[2];
	for(int i=3;i<=n+1;i++){
		if(a[i] & a[i-1] > b){
			b = a[i] & a[i-1];
		}
	}
	cout<<b;
	return 0;
} 
