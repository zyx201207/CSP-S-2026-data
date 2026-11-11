#include <bits/stdc++.h>
using namespace std;
long long a[200010];
long long b[200010];
int c[200010];
int d[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>a[i]>>x;
		c[i]=x-'a'+1;
		b[n-i+1]=a[i];
		d[n-i+1]=c[i];
	}
	unsigned long long cnt=0;
	int la=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=b[la])
		{
			while(a[i]>0)
			{
				if(d[la]!=c[i])
				{
					cnt+=min(a[i],b[la]);
				}
				if(a[i]<b[la])
				{
					b[la]-=a[i];
					a[i]=0;
				}
				else
				{
					a[i]-=b[la];
					b[la]=0;
					la++;
					//cout<<cnt<<endl;
				}
			}
		}
		else
		{
			if(d[la]!=c[i])
			{
				cnt+=a[i];
			}
			//la++;
			b[la]-=a[i];
			a[i]=0;
			if(b[la]==0)
			{
				la++;
			}
			/*if(i==3)
			{
				cout<<la<<endl;
			}*/
			
		}
		//cout<<cnt<<endl;
	}
	
	cout<<cnt/2;
	return 0;
}
