#include<bits/stdc++.h>
using namespace std;
long long n,qw,ans,opo,cnt,a[200005];
char wq,op,x[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>qw>>wq;
		if(i==1)op=wq,opo=qw;
		else
		{
			if(op==wq)
			{
				opo+=qw;
			}
			else
			{
				cnt++;
				a[cnt]=opo;
				x[cnt]=op;
				opo=qw;
				op=wq;
			}
		}
	}
	cnt++;
	a[cnt]=opo;
	x[cnt]=op;
	for(int l=1,r=cnt;r>=1&&l!=r&&l<=cnt;l=l)
	{
		if(x[l]!=x[r])
		{
			if(a[l]<=a[r])
			{
				ans+=a[l];
				a[r]-=a[l];
				a[l]=0;
				if(a[r]==0)
				r--;
				l++;
			}
			else
			{
				ans+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
		}
		else
		{
			if(a[r]>=a[l])
			{
				a[r]-=a[l];
				a[l]=0;
				if(a[r]==0)
				r--;
				l++;
			}
			else
			{
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
		}
	}
	cout<<ans;
}
//nizenmezhidaowo5=1 s light
