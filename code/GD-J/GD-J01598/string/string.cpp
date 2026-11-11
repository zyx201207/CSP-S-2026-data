#include<bits/stdc++.h>
using namespace std;
long long a[200050];
int num=0,n;
string c,cc;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int l=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i]>>cc[i];
    	l+=a[i];
	}
	int p=0;
	for(int i=0;i<n;i++)
	{
		p+=a[i];
		for(int j=p-a[i];j<l;j++)
		{
			for(int k=0;k<a[i];k++)
			{
				c[j]=cc[i];
			}
		}
	}
	for(int j=0;j<l/2;j++)
	{
		if(c[j]!=c[l-j-1])
		{
			c[l-j-1]=c[j];
			num++;
		}
	}
	cout<<num;
	return 0;
}
