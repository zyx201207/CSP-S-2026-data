#include <bits/stdc++.h>
using namespace std;
long long a[10005];
long long cnt=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	long long p;
	
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		p=a[1];
	}
	for(long long i=2;i<=n;i++)
	{
		if(p==a[i])
		{
			cnt++;
			break;
		}
		else if(p=a[i]+m)
		{
			cnt++;
			break;
		}
		else if(p+m==a[i])
		{
			cnt++;
			break;
		}
		else if (p+1==a[i])
		{
			m--;
			cnt++;
			break;
		}
		else if(p+m-n==a[i])
		{
			cnt++;
			break;
		}
		else if(m==0)
		{
			break;
		}
		
	}
	
	cout<<cnt;
	return 0;
}
