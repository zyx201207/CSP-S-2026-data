#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct o
{
	string s;
	long long c;
}a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0;
	long long n;
	cin>>n;
    string b;
    for(long long i=1;i<=n;i++)
    {
    	cin>>a[i].c>>a[i].s;
	}
	bool flag=true;
	for(long long i=1;i<=n-1;i++)
	{
		if(a[i].s!=a[i+1].s) flag=false;
	}
	
	if(flag)
	{
		cout<<0;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
           for(int j=1;j<=a[i].c;j++)
           {
           	b+=a[i].s;
		   }
		}
		if(b.size()%2==1)
		{
			int cnt=b.size()/2;
            int l=cnt-1,r=cnt+1;
		    while(l>=0&&r<=b.size()-1)
		    {
		    	if(b[l]!=b[r]) sum++;
		    	l--;
		    	r++;
			}
		}
		else
		{
			int cnt=b.size()/2-1;
			int l=cnt,r=cnt+1;
			while(l>=0&&r<=b.size()-1)
		    {
		    	if(b[l]!=b[r]) sum++;
		    	l--;
		    	r++;
			}
		}
	}cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
	}
