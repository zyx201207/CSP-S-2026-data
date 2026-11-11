#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string ss;
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	long long a=0;char s;
    	cin>>a>>s;
    	while(a--)
    		ss+=s;
	}
	long long si=ss.size();
	for(int i=0;i<si/2;i++)
	{
		if(ss[i]!=ss[si-i+1])cnt++;
	}
	cout<<cnt;
    return 0;
}
