#include<bits/stdc++.h>
using namespace std;
int n,a[1000000];
string s[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and .out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n%2==0)cout<<a[n/2];
	else cout<<a[n/2+1];
	return 0;
}
