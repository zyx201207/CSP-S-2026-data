#include <bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
long long mp[500005];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[2]-a[1]==a[3]-a[2]&&a[2]-a[1]==(a[n]-a[1])/n)
	{
		long long an=m/(a[2]-a[1]);
		long long s=a[2]-a[1];
		while(an-s>=0)
		{
			an-=s;
			s++;
		}
		cout<<s;
	}
	else{
		for(int i=1;i<=n;i++)
		{
			long long maxm=0;
			for(int j=1;j<=i;j++)
			{
				mp[j]=a[i]-a[j];
				b[j]=mp[j];
			}
			sort(b+1,b+1+i);
			for(int j=1;j<=i;j++)
			{
				if(m>=sum+b[j])
				{
				   sum+=b[j];
				   maxm++;
				}
			}
			sum=0;
			maxn=max(maxn,maxm);
		}
		cout<<maxn;
	}
	return 0;
	
}
