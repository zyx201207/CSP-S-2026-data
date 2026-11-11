#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
string x;
long long n,js=0;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;++i)
{
	cin>>a[i]>>x[i];
}
long long l=1,r=n;
while(l<r)
{
	if(x[l]!=x[r]) 
	{
		js=js+min(a[l],a[r]);
		if(a[l]==a[r])
		{
			l+=1;
			r-=1;
		}
		else if(a[l]>a[r])
			{
				a[l]=a[l]-a[r];
				r=r-1;
			}
		else if(a[l]<a[r])
			{
				a[r]=a[r]-a[l];
				l=l+1;
			}
	}
	else{
		if(a[l]==a[r])
		{
			l+=1;
			r-=1;
		}
		else if(a[l]>a[r])
			{
				a[l]=a[l]-a[r];
				r=r-1;
			}
		else if(a[l]<a[r])
			{
				a[r]=a[r]-a[l];
				l=l+1;
			}
	}
}
cout<<js;
return 0;
}
