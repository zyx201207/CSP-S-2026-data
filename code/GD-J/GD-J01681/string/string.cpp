#include<bits/stdc++.h>
using namespace std;
int n,l,t,w;
char x,a[3000010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l>>x;
		t+=l;
		for(int j=t-l+1;j<=t;j++)
		{
			a[j]=x;
		}
	}
	for(int j=1;j<=(t+1)/2;j++)
	{
		if(a[j]!=a[t+1-j])
		{
			w++;
		}
	}
	cout<<w;
	return 0;
}
