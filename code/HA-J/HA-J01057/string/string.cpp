#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;char v;
long long int a[1000005],b[1000],c,d,e,f=1,g,n,t;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		cin>>s;
		f+=b[i];
		
		for(int j=0;j<b[i];j++)
	    {
	    	a[t]=s[0]-'a'+1;
			t++;
	    }
	}
	e=f/2;
	a[t]=s[0]-'a'+1;
	for(int j=0;j<e;j++)
	{
	    if(a[j]!=a[t-j-1])
	    {
	    	c++;
		}
	}
	cout<<c;
	return 0;
}

