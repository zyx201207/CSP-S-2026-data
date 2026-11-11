#include<bits/stdc++.h>
using namespace std;
int res=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	int mid;
	long long a[500005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	int l;
	int r;
	mid=(n/2)+1;
	l=mid-1;
	r=mid+1;
	while(m>0)
	{
		
		if(abs(a[mid]-a[l]) < abs(a[r]-a[mid]) && l!=0 && a[mid]!=a[l] && a[mid]!=a[r])
		{	
			res++;
			m=m-abs(a[mid]-a[l]);
			if(m<0)
			{
				res--;
				break;
			}
			l--;
		}
		else if(abs(a[mid]-a[l]) > abs(a[r]-a[mid]) && a[r]!=0 && a[mid]!=a[r] && a[mid]!=a[l])
		{
			res++;
			m=m-abs(a[r]-a[mid]);
			if(m<0)
			{
				res--;
				break;
			}
			r++;
		}
		else if(abs(a[mid]-a[l])==abs(a[r]-a[mid]) && a[l]!=0 && a[r]!=0 && a[mid]!=a[l] && a[mid]!=a[r])
		{
			res+=2;
			m-=abs((a[mid]-a[l])*2);
			if(m<0)
			{
				res-=2;
				break;
			}
			r++;
			l--;
		}
		else if(a[mid]==a[l] && a[l]!=0)
		{
			res++;
			l--;
		}
		else if(a[mid]==a[r] && a[r]!=0)
		{
			res++;
			r++;
		}
		if(m<0)
		break;
	}
	cout<<res;
	return 0;
}
