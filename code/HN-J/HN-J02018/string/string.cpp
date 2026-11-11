#include <bits/stdc++.h>
using namespace std;
int main ()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    string weiwen;
    int a;
    cin>>a;
    long long sum=0;
    for(int i=1;i<=a;i++)
    {
    	long long n=0;
    	cin>>n;
    	string s;
    	cin>>s;
    	for(int j=1;j<=n;j++)
    	{
    		weiwen+=s;
		}
	}
	for(int i=0;i<weiwen.size()/2;i++)
	{
		if(weiwen[i]!=weiwen[weiwen.size()-i-1])
		{
			sum+=1;
		}
	}
	cout<<sum;
    return 0;
 } 
