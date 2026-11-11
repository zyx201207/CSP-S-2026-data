#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long sum[500005];
int a[500005];
long long l,r,mid;
long long max_ = 0;
long long L,R;
int N;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)	
	{
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)	
	{
		sum[i] = sum[i-1] + a[i];
	}
	l = 1;
	r = n;
	for(int i = n;i>=1;i--)
	{
		r = i;
		l = 1;
		while(r-l>1)
		{
			mid = (r+l)/2;
			
			if(((a[i])*(i-mid+1)-(sum[i]-sum[mid-1]))>m)
			{
				l = mid;
			}
			else
			{
				r = mid;
				
				
			}
			
		}
		
		if(i-l>max_)
		{
			L = l;
			R = r;
			N = i;
		}
//		if(l==1) l--;
		if(l==1) l--;
		max_ = max(max_,i-l);
		
	}
//	cout<<L<<" "<<R<<N<<endl;
	
	cout<<max_;
/*
5 8
-3 -1 2 2 7
-3 -1 2 2 7
*/
	return 0;
}
