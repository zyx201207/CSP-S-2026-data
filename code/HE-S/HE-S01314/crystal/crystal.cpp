#include<bits/stdc++.h>
using namespace std;
int n=0,m=0;
int a[1000000],hc,ans=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==0)
	{
		hc=a[n/2];
		int sheng=m;
		for(int i=n/2;i>=1;i--)
		{
			sheng=m-(hc-a[i]);
			ans++;
			if(sheng<0)
			{
				ans--;
				break;
			}
		}
	}
	else
	{
		hc=a[(n+1)/2];
		
		int sheng=m;
		for(int i=(n+1)/2;i>=1;i--)
		{
			sheng=m-(hc-a[i]);
			ans++;
			if(sheng<0)
			{
				ans--;
				break;
			}
		}
	}

	cout<<ans;
	return 0;
}
