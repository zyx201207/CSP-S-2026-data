//GZ-J00262遵义四十九中学 万昱丞
#include<bits/stdc++.h>
using namespace std;
int b[10000000],cnt,sum=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n],s[n]
	for(int q=1;q<=n;q++)
	{
		cin>>a[q]>>s[q];
		for(int j=sum;j<=a[q];j++)
		{
			b[j]=s[q];
		    sum+=a[q];
		}
	}
    for(int e=1;e<=sum/2;e++)
    {
    	if(b[e]!=b[sum-e+1])cnt++;
	}
	cout<<cnt;
	return 0;
}
