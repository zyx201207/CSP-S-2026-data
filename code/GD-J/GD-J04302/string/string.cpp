#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c = 0,i = 0,j = 0,v = 0;
	cin>>n;
	int a[n] = {0};
	char b[n] = {'0'};
	for(i = 0;i<n;i++) cin>>a[i]>>b[i];
	
	for(i = 1;i<n;i++) if(b[i] != b[i - 1]) v = 1;
	if(n == 1 || v == 0)
	{
		cout<<0;
		return 0;
	}
	
	
	for(i = 0,j = n - 1;i<n / 2;i++)
	{
		if(a[i] != a[j] || b[i] != b[j]) v = 1;
			j--;
	}
	if(v == 0)
	{
		cout<<0;
		return 0;
	}
	
	v = 0;
	string qp,p,q;
	for(i = 0;i<n;i++) for(j = 0;j<a[i];j++) qp += b[i];
	for(i = 0;i<qp.size() / 2;i++) p += qp[i];
	for(i = qp.size() - 1;i>n / 2 + 1;i--) q += qp[i];
	for(i = 0;i<=n / 2;i++) if(q[i] != p[i]) c++;
	cout<<c;
	return 0;
}
