#include<bits/stdc++.h>
using namespace std;
bool h(string k1,string k2)
{
	int kk=k1.size();
	for(int i=0;i<kk/2;i++)
	{
		swap(k1[i],k1[kk-1-i]);
	}
	for(int i=0;i<kk;i++)
	{
		if(k1[i]-'0'!=k2[i]-'0')
		{
			return 0;
		}
	}
	return 1;
}
int h1(string k1)
{
	int sum=0;
	int kk=k1.size();
	for(int i=0;i<kk/2;i++)
	{
		if(k1[i]-'0'!=k1[kk-1-i]-'0')
		{
			sum++;	
		}
	}
	return sum;
}
long long a,n;
string c,k;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			k=k+c;
		}
	}
	if(h(k,k))
	{
		cout<<0;
		return 0;
	}
	cout<<h1(k);
	return 0;
}
