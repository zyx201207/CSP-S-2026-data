#include<bits/stdc++.h>
using namespace std;
int n,m,x=0;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	x=a[n];
	for(int i=1;i<m;i++){
		x=x&a[n-i];
	}
	cout<<x;
	return 0;
}

