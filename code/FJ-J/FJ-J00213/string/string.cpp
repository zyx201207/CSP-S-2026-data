#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node{
	long long x;
	char s;
}a[N];
vector <node> b;
int main(){
	freopen("string4.in","r",stdin);
	freopen("string_4.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].x;
		cnt+=a[i].x;
		cin>>a[i].s;
	}
	long long ans=0;
	long long k=cnt/2;
	long long sum=0,j=0;
	for(long long i=1;i<=n;i++)
	{
		sum+=a[i].x;
		if(sum>=k)
		{
			j=i;
			break;
		}
	}
	sum-=k;
	for(long long i=1;i<j;i++)
	{
		b.push_back({a[i].x,a[i].s});
	}
	b.push_back({a[j].x-sum,a[j].s});
	if(sum!=0)
	{
		b.push_back({sum,a[j].s});
	}
	for(long long i=1;i<=j;i++)
	{
		b.push_back({a[i+j].x,a[i+j].s});
	}
	long long l=0; 
	for(long long i=b.size()-1;i>=0;i--)
	{
		if(b[i].x==0)
		{
			continue;
		}
		else
		{
			l=i;
			break;
		}
	}
	for(long long i=0;i<j;i++)
	{
		if(b[i].x==b[l].x)
		{
			if(b[i].s==b[l].s)
			{
				l--;
				continue;
			}
			else
			{
				ans+=b[i].x;
				l--;
				continue;
			}
		}
		else if(b[i].x>=b[l].x)
		{
			long long r=l;
			while(b[r].x<=b[i].x)
			{
				b[i].x-=b[r].x;
				if(b[i].s!=b[r].s)
				{
					ans+=b[r].x;
				}
				r--;
			}
			l=r;
			if(a[i].x==0)
			{
				i++;
			 } 
		}
		else
		{
			long long r=i;
			while(b[l].x>=b[r].x)
			{
				b[l].x-=b[r].x;
				if(b[r].s!=b[l].s)
				{
					ans+=b[r].x;
				}
				r++;
			 } 
			 i=r;
			 if(b[l].x==0)
			 {
			 	l--;
			 }
		 } 
	}
	cout<<ans;
	return 0;
}
