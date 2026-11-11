#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long sum=0;
	int a[200001];
	char c[200001];
	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		sum=sum+a[i];
		if(c[i]==c[i-1])
		{
			a[i-1]+=a[i];
			i--;
		}
	}
	long temp=ceil(sum/2);
	int i=0,j=n;
	int t1=0,t2=a[j];
	long k=0;
	while(k<temp)
	{
		
		if(c[i]!=c[j])
		{
			ans++;
			t1++; t2--;
		}
		if(t1==a[i])
		{
			i++;
			t1=0;
		}
		if(t2==0)
		{
			j--;
			t2=a[j];
		}
		k++;
	/*	int next=min(a[i]-t1,t2);
		if(k+next<=temp)
		{
			next=next;
		}
		else
		{
			next=temp-k;
			if(c[i]!=c[j])
			{
				ans=ans+next;
				k=k+next;
			}
			cout<<ans;
			return 0;
		}
		if(c[i]!=c[j])
		{
			ans=ans+next;
			k=k+next;
		}
		t1=t1+next;
		t2=t2-next;
		if(t1==a[i])
		{
			i++;
			t1=0;
		}
		if(t2==0)
		{
			j--;
			t2=a[j];
		}*/
	}
	cout<<ans;
	
	return 0;
}
