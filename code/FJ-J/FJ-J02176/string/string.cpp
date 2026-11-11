#include<bits/stdc++.h>
using namespace std;
int main()
{freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	long long n,a[200001],ans=0;
	char b[200001];
	cin>>n;
	int c=1,d=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(c!=d)
	if(b[c]!=b[d])
	{if(a[c]>a[d])
	{a[c]-=a[d];
	ans+=a[d];
	d--;
	}
	else
	{a[d]-=a[c];
	ans+=a[c];
	c++;
	}
	}
	else
	{if(a[c]>a[d])
	{a[c]-=a[d];
	d--;
	}
	else
	{a[d]-=a[c];
	c++;
	}
	
	}
	cout<<ans;
}