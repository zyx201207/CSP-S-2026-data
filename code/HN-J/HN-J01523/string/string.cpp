#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,b;
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int ai;
		char c;
		cin>>ai>>c;
		for(;ai>0;ai--)
		{
			a=a+c;
			b=c+b;
		}
	}
	for(int i=0;i<a.size()/2+1;i++)
	{
		if(a[i]!=b[i]) ans++;
	}
	cout<<ans;
	return 0;
}
