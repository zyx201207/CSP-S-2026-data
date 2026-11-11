#include <bits/stdc++.h>
using namespace std;
long long n,x,sum=0,num=1;
string s;
char y;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> x >> y;
		for(int j=num;j<=num+x;j++)
		{
		    s[j]=y;	
		}
		num+=x;
	}
	for(long long h=1;h<=num/2;h++)
	{
	    if(s[h]!=s[num-h+1])
	    {
		    sum++;	
		}
    }
    cout << sum;
		return 0;
}
