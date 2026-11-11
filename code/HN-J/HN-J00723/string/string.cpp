#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,q;
	cin>>n;
	int a[200005];
	char x;
	string w,m;
	long long sum=0,l=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>x;
		for(int j=1;j<=a[i];j++)
		{
			w+=x;
		}
	}
	for(int i=0;i<w.size();i++)
	{
		m+=w[w.size()-i-1];
	}
	l=w.size();
	if(l%2==1)
	{
		l--;
	}
	for(int i=0;i<(l/2);i++)
	{
		if(w[i]!=m[i])
		{
			sum++;
		}
	}
	cout <<sum;
	return 0;
}

