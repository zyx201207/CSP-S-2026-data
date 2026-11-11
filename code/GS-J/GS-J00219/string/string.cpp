#include <bits/stdc++.h>
using namespace std;
int a[105],ans,h,k;
string b[105];
int main()
{
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		ans+=a[i];
	}
	while (h<ans)
	{
		k++;
		h+=k^k;
	}
	cout<<k;
	return 0;
}
