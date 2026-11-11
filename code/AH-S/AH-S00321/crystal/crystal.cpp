#include<bits/stdc++.h>
using namespace std;
long long int n,m;
long long int a[1001000];
long long int ans,x,mak=INT_MAX,pandan=0;
long long int book=INT_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		if(pandan==1)
		{
			break;
		}
		if(mak>i)
		{
			x=m;
			ans=1;
			mak=i;
		}
		else
		{
			x=x+(i+1-mak)*(a[i+1]-a[i]);
			ans=ans-1;
		}
		for(int j=mak-1;j>=1;j--)
		{
			if(a[i]-a[j]<=x)
			{
				ans=ans+1;
				x=x-(a[i]-a[j]);
				mak=j;
			}
			else
			{
				break;
			}
			if(mak==1)
			{
				pandan=1;
			}
		}
		if(ans>book)
		{
			book=ans;
		}	
	}
	cout<<book;
	return 0;
}
