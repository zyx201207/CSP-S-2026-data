#include <bits/stdc++.h>
using namespace std;
int n,a[100000001],t=1,b,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>b>>c;
		for(int j=t;j<=t+b-1;j++) a[j]=(int)(c-'a');
		t+=b;
	}
	t--;
	for(int i=1;i<=(t+1)/2;i++) if(a[i]!=a[t-i+1]) ans++;
	cout<<ans;
	return 0;
}
