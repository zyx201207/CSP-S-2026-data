#include<bits/stdc++.h>
using namespace std;
int a[99999999];
int n,m,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	b=a[n];
	n-=1;
	for(int i=1;i<=m-1;i++){
		b&=a[n];
		n--;
	}
	cout<<b;
	return 0;
}
