#include<bits/stdc++.h>
using namespace std;
long long n,m,crystal[5000010],k;
bool check(long long mid)
{
	long long cnt=0;
	for(long long i=mid-1;i<n;i++)
	{
		cnt=0;
		if((crystal[i]-crystal[i-mid-1])*mid<m) return true;
		if(!A)
		{
			for(long long j=0;j<mid;j++)
			{
				cnt+=crystal[i]-crystal[i-j];
				if(cnt>m) j+=1000000000;
			}
		}
		else cnt=((mid-1)*mid)/2;
		if(cnt<=m) return true;
	}
	return false; 
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++) 
		cin>>crystal[i];
	long long l=0,r=n;
	while(l<r-1)
	{
		long long mid=l+(r-l)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
} 
