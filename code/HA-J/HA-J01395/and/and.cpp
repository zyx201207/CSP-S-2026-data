#include<bits/stdc++.h>
using namespace std;
int n,m,c=0;
long long a[200005];
int main(){
	freopen ("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	c=a[1];
	for(int i=2;i<=m;i++){
		c&=a[i];
	}
	cout<<c;
	return 0;
}
