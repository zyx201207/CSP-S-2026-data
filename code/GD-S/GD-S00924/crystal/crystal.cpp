//crystal

#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],num=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int k=m;
	sort(a+1,a+n+1);
	int l=n/2,r=n/2+1;
	while(l&&r<=n)
	{
		if(a[r]-a[l]<=a[r+1]-a[r]&&k-(a[r]-a[l])>=0)
		{
			k-=(a[r]-a[l]);
			l--;
			num++;
		}
		else if(k-(a[r+1]-a[r])>=0)
		{
			k-=(a[r+1]-a[r]);
			r++;
			num++;
		}
		else break;
	}
	cout<<num;
}

