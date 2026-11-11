#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100000009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxx=0;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,a[i]&a[i-1]);
	}
	cout<<maxx;
	return 0;
} 
