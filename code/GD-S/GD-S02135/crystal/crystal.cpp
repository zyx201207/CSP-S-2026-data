#include<bits/stdc++.h>
using namespace std;
long long n,m,perfectnum,ans;
long long a[500100];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		perfectnum+=a[i];
	}
	perfectnum/=n;
	sort(a+1,a+1+n);
	int left = 1,right = n,mid = (left+right)/2;
	while(left<right)
	{
		if((right-left) == 2)
		{
			perfectnum = mid;
			break;
		}
		if(a[left] == perfectnum)
		{
			perfectnum = a[left];
			break;
		}
		if(a[right]==perfectnum)
		{
			perfectnum = a[right];
			break;
		}
		if(a[mid]==perfectnum)
		{
			perfectnum = a[mid];
			break;
		}
		if(a[mid]>perfectnum)
		{
			right = mid;
			mid = (left+right)/2;
			continue;
		}
		if(a[mid]<perfectnum)
		{
			left = mid;
			mid = (left+right)/2;
		}	
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==perfectnum)
		{
			mid = i;
			break;
		}
	}
	int x = mid-1;
	while(m)
	{
		if(perfectnum - a[x] <= m)
		{
			m-=a[x];
			a[x] = perfectnum;
			x--;
		}
		else
		{
			m = 0;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		//cout<<a[i]<<" ";
		if(a[i] == perfectnum)
		{
			ans++;
		}
	}
	//cout<<endl;
	//cout<<perfectnum<<" "<<mid<<" ";
	cout<<ans;
	return 0;
}

