#include <bits/stdc++.h>
using namespace std;
int n;
char a[200000005];
long long sum,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++)
		a[j+sum]=y;
		sum+=x;
	}
	for(int i=1;i<=sum/2;i++){
		if(a[i]!=a[n-i+1])
		ans++;
	}
	cout<<ans;
	return 0;
}
