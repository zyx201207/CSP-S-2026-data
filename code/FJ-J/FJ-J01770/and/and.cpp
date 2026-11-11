#include<bits/stdc++.h>
using namespace std;
const int N=1e6+20;
long long a[N];
struct node
{
	long long h,c;
}b[N];
bool cmp(node x,node y)
{
	return x.h>y.h;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i].c=a[i];
		long long quan=0;
		long long j=1;
		long long ans=1;
		for(j=1;j=j*2;)
		{
			ans++;
			if(j>=a[i])break;
		}
		for(long long k=j;k>0;k=k/2)
		{
			if(a[i]>=k)
			{
				a[i]=a[i]-k;
				quan=quan+ans*k;
			}
			ans--;
			if(a[i]==0)break;
		}
		b[i].h=quan;
	 } 
	sort(b,b+n,cmp);
	long long mx=-1;
	for(long long i=0;i<=n-m;i++)
	{
		long long he=b[i].c;
		for(long long j=i+1;j<i+m;j++)
		{
			he=he&b[j].c;
			if(he==0)break;
		}
		mx=max(mx,he);
		if(mx!=0)
		{
			break;
		 } 
	}
	cout<<mx<<endl;
	return 0;
}
