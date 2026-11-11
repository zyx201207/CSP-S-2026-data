#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[1000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//srand(time(NULL));
	//printf("%d",rand%1000005);
	long long n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	int zh=n;
	long long z=a[zh],c=0,cnt=0;
	while(zh>=1)
	{
		z=a[zh];
		c=0;
		for(int i=1;i<=zh;i++)
		{
			if(z-a[i]<0) break;
			c+=z-a[i];
			b[i]=z;
		}
		
		//for(int i=1;i<=n;i++) cout<<b[i]<<" ";
		//cout<<zh<<endl;
		if(c==m) break;
		else 
		{
			zh--;
			for(int i=1;i<=zh;i++) b[i]=a[i];
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==z) cnt++;
	}
	cout<<cnt;
	return 0;
}
