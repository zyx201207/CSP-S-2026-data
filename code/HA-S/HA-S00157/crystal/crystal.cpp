#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
const long long M=9e9;

long long m;
int n,ans,ma;
long long a[N],b[N];
unsigned long long lj[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	
	sort(a+1,a+n+1);
	
	for(int i=2;i<=n;++i)
	{
		if(a[i]==a[i-1])lj[i]=abs(a[i])+lj[i-1];
		else lj[i]=lj[i-1];
		b[i]=a[i]-a[i-1]+b[i-1];
	}
	
	for(int i=1,l,r,mid;i<=n;++i)
	{
		l=1,r=i;
		while(l<r)
		{
			mid=l+r>>1;
			if(b[i]-b[mid]+(lj[i]-lj[mid])>=m&&(m<=M))l=mid+1;
			else if(b[i]-b[mid]>=m)l=mid+1;
			else r=mid;
		}
		
		if(i-r>ma)ma=i-r;
	}
	
	for(int i=1;i<=n;++i)cout<<a[i]<<' '<<lj[i]<<'\n';
	
	cout<<ma+1<<'\n';
	
	return 0;
}
