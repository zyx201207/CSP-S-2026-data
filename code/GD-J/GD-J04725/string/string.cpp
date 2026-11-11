#include <bits/stdc++.h>
using namespace std;
long long n,a[500000],sum;
char b[500000];
int main()
{
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n;
	string w;
	for(long long  i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(long long k=1;k<=a[i];k++)
		{
			w+=b[i];
		}
	}
    long long  len,ss;
    len=w.size();
    if(len%2!=0)
    {
    	ss=(len+1)/2;
    	for(long long i=0;i<ss-1;i++)
    	{
    		if(w[i]!=w[len-i-1])
    		{
    			sum++;
			}
		}
	}
	else
	{
		ss=len/2;
		for(long long i=0;i<ss;i++)
		{
		    if(w[i]!=w[len-i-1])
    		{
    			sum++;
			}
		}
		
	}
	cout<<sum;
	return 0;
}
