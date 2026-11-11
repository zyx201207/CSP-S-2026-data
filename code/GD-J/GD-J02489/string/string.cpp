#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[10005];
	string s[10005];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	sort(a+1,a+n+1);
	cout<<a;
	return 0;
}
