#include<bits/stdc++.h>
using namespace std;

int n;
long long ans=0,flag=0;
long long a[20002];
char c[20002];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %c",&a[i],&c[i]);
	}
	int i=1,j=n;
	int temp=a[1];
	while(i<j)
	{
		if(temp<a[j])
		{
			if(c[i]!=c[j]) ans+=temp;
			a[j]-=temp;
			i++;
			temp=a[i];
		}
		else if(temp>a[j])
		{
			if(c[i]!=c[j]) ans+=a[j];
			temp-=a[j];
			j--;
		}
		else{
			if(c[i]!=c[j]) ans+=temp;
			i++;
			temp=a[i];
			j--;
		}
	}
	
	cout<<ans;
	
	return 0;
}
