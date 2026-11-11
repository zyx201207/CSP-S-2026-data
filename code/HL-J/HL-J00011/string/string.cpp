#include<bits/stdc++.h>
using namespace std;
long long a[200050],c[200050];
char b[200050];
string aa,bb;
long long m,d;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++)
		{
			aa+=b[i];
		}
	}
	
	long long s=aa.size();
	for(int i=0;i<s;i++)
	{
		bb+=aa[s-i-1];
	}
	if(aa==bb)
	{
		cout<<"0";
		return 0;
	}
	for(int i=0;i<s;i++)
	{
		if(aa[i]!=bb[i])
		{
			m++;
		}
	}
	cout<<m/2;


	return 0;
}

