#include <bits/stdc++.h>
using namespace std;
long long a[100000005];
char s[100000005];
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		ans+=a[i];
	}
	long long m;
	cout <<ans/2;
	return 0;
}
