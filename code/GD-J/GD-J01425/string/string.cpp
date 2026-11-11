#include <bits/stdc++.h>
using namespace std;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	int a[n];
	int b[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		if(b[i]!=b[i-1]){
			cnt++;
		}
	}
	cout<<cnt-1;
	return 0;
}
