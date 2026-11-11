#include<bits/stdc++.h>
using namespace std;
int n,m;
const int M=5e5+5;
long long a[M];
long long sum;
long long maxn=INT_MIN;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;	
	long long ind=n-1,c=0;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort (a+1,a+n+1,less<int>()); 
	for(int i=n;i>0;--i)
	{
		if(i!=n)
		{
			sum-=c*(a[i+1]-a[i]);
			--c;
		}
			
		while(sum+(a[i]-a[ind])<=m && ind>=1)
		{
			sum+=a[i]-a[ind];
			ind--;
			++c;
		}
		maxn=max(maxn,c);
		//cout<<c<<" ";
	}
	cout<<maxn+1;
	return 0;
}

