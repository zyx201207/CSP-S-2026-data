#include <bits/stdc++.h>
using namespace std;
int n,a[200005],num[100000005],cnt=0;
string s;
char c;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		num[i]=a[i]+num[i-1];
		for(int j=num[i-1];j<num[i];j++)
		{
			s[j]=c;
		}
    }
    for(int i=0;i<s.size()/2;i++)
    {
    	if(s[i]!=s[n-i]) cnt++;
	}
	cout<<cnt;
	return 0;
 } 
