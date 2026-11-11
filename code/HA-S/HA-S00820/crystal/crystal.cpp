#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n;
long long m,zhong=1,hua=1;
cin>>n>>m;



for(int i=1;i<=n;i++)
	{
		cin>>a[i];
			}

sort(a+1,a+n+1);
int l=1,r=2,ans=0;long long s=0;//s-l+1
	while(r<=n&&l<=r)
	{
		while(s<=m&&r<=n)
		{s=0;for(int i=l;i<=r;i++)s+=a[r]-a[i];
	r++;
		}if((r-l-1)>ans){
		ans=r-l-1;}
		while(s>=m&&l<r){
		s-=a[r]-a[l];l++;}s=0;
	}cout<<ans;
	
return 0;
}

