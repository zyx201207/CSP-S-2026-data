#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[300010],a1[300010];
int b[300010],b1[300010];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	int m=t;
	int n=0,n1=0;
	int cnt=t;
	for(int i=1;i<=t;i++) 
	{
		cin>>b[i]>>a[i];
		a1[cnt]=a[i];
		b1[cnt]=b[i];
		cnt--;
		n+=b[i];
	}
	if(n%2==1) n--;
	n/=2;
	n1=n;
	int sum=0,sum1=0;
	for(int i=1;i<=t;i++)
	{
		if(b[i]<n)
		{
			while(b[m]<=b[i])
			{		
				if(a[m]!=a[i])
				{
					sum+=b[m];
				}
				b[m]=max((long long)0,b[m]);
				b[i]-=b[m];	
				n-=b[m];
				//	cout<<"m="<<m<<" b[m]="<<b[m]<<" a[m]="<<a[m]<<" i="<<i<<" b[i]="<<b[i]<<" a[i]="<<a[i]<<" sum="<<sum<<"\n";
				m--;
			}
			if(b[i]>0)
			{
				b[m]-=b[i];
				n-=b[i];
				if(a[m]!=a[i])
				{
					sum+=b[i];
					b[i]=0;
				}
			}
		}
		else
		{
			b[i]-=n-1;
			n-=b[i];
			for(int j=i+1;j<=t;j++)
			{
				n-=b[j];
				if(a[i]!=a[j])
				{
					sum+=b[j];
				}
				if(n<=0) break;
			}
		}
		if(n<=0) break;
	}
	m=t;
	for(int i=1;i<=t;i++)
	{
		if(b1[i]<n1)
		{
			while(b1[m]<=b1[i])
			{		
				if(a1[m]!=a1[i])
				{
					sum1+=b1[m];
				}
				b1[m]=max((long long)0,b1[m]);

				b1[i]-=b1[m];	
				n1-=b1[m];
				m--;
			}
			if(b1[i]>0)
			{
				b1[m]-=b1[i];
				n1-=b1[i];
				if(a1[m]!=a1[i])
				{
					sum1+=b1[i];
					b1[i]=0;
				}
			}
		}
		else
		{
			b1[i]-=n1-1;
			n1-=max((long long)0,b1[i]);
			for(int j=i+1;j<=t;j++)
			{
				n1-=max((long long)0,b1[j]);
				if(a1[i]!=a1[j])
				{
					sum1+=b1[j];
				}
				if(n1<=0) break;
			}
		}
		if(n1<=0) break;
	}
	cout<<min(sum,sum1);
	return 0;
}
