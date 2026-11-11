#include<bits/stdc++.h>
using namespace std;
int n=0,a,sum;
string m,l,v;
char x;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>x;
		while(a--)
		{
			m+=x;
		}
	}
	for(int i=m.size()-1;i>=0;i--)
	{
		l+=m[i];
	}
	if(m==l)
	{
		cout<<0;
		return 0;
	}
	for(int i=m.size()-1,j=m.size()-1;i>=0;i--)
	{
		v="";
    	if(m[i]!=l[i])
		{
			sum++;
			m[i]=l[j];
		}
		for(int i=m.size()-1;i>=0;i--)
    	{
    		v+=m[i];
    	}
    	if(v==m)
    	{
    		cout<<sum;
    		return 0;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
}
