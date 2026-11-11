#include<bits/stdc++.h>
using namespace std;
long long a[9000000000000999],b[9000000000000999];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	long long n,m,cnt;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
	{
		b[i]=a[i+1]-a[i]; 
		cnt+=a[i+1]-a[i];
	}
	sort(b,b+n-1);
	long long p=cnt-m,ans=0;
	for(int i=n-2;i>=0;i--)
	{
		if(b[i]<=p)
		{
			if(b[i]==p)
			{
				ans+=1;
				break;
			}
			else{
				p-=b[i];
				ans+=1;
			}
		}
		else{
			continue;
		}
	}
	cout<<ans<<endl;
	return 0;
}
