#include<bits/stdc++.h>
using namespace std;
long long b[200005],n,l=0,r,f,mid;
char a[200005],chl,chr;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;r=n+1;
	for(int s=1;s<=n;s++)cin>>b[s]>>a[s];
	while(l<r)
	{
		if(b[l]==0)l++;
		if(b[r]==0)r--;
		if(b[l]>b[r])
		{
			f+=(a[l]!=a[r])*b[r];
			b[l]-=b[r];
			b[r]=0;
		}
		else 
		{
			f+=(a[l]!=a[r])*b[l];
			b[r]-=b[l];
			b[l]=0;
		}
	}
	cout<<f;
	return 0;
}
