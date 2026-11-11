#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum;
    long long a[1000005];
    string s[10000005];
    string t[10000005];
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	for(int i=1,j=1;j<=sum;j++)
	{
		t[j]=s[i];
		a[i]--;
		if(a[i]==0)i++;
	}
	if(n==2 && s[1]==s[n])
	{
		cout<<0;
		return 0;
	}if(n==2 && s[1]!=s[n])
	{
		cout<<1;
		return 0;
	}
	long long cnt=0;
	int i=1,j=sum;
	while(i!=j)
	{
	    if(t[j]!=t[i])
		{
			t[j]=t[i];
			cnt++;
			i++;
			j--;
		}
	}
	
	cout<<cnt;


     return 0;
}
