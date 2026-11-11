#include<bits/stdc++.h>
using namespace std;
long long n,m,x,a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		x=min(a[i],a[i+1]);
	}
	cout<<x;
	return 0;
}