#include <bits/stdc++.h>
using namespace std;
long long num[200010];
char c[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,t=0;
    long long ans=0,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		long long x;
		char z;
		ans+=x;
		cin>>x>>z;
		if(z!=c[t]) num[++t]=x,c[t]=z;
		else if(z==c[t]) num[t]+=x;
    }
    if(t==1)
	{
		cout<<0;
		return 0;
	}
	ans=(ans+1)/2;
	int i=1,j=t;
	while(i<=j)
	{
		if(c[i]==c[j])
		{
			if(num[i]==num[j]) i++,j--;
			else if(num[i]<num[j]) num[j]-=num[i],i++;
			else if(num[i]>num[j]) num[i]-=num[j],j--;
		}
		else if(c[i]!=c[j])
		{
			if(num[i]==num[j]) sum+=num[i],i++,j--;
			else if(num[i]<num[j]) sum+=num[i],num[j]-=num[i],i++;
			else if(num[i]>num[j]) sum+=num[j],num[i]-=num[j],j--;
		}
	}
	cout<<sum;
    return 0;
}
