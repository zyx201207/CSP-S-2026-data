#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll a[N],b[N],len[N];
int c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>a[i]>>x;
		b[i]=sum+a[i];
		a[i]=sum+1;
		c[i]=x-'a',sum+=a[i],len[i]=b[i]-a[i]+1;
	}/*
	ll tsum=0;
	for(int i=1;i<=n;i++)
	{
		tsum+=a[i];
		if(sum%2)
		{
			if(tsum>=sum/2+1)
				
		}
	}*/
	int l=1,r=n;
	ll ans=0;//,mid
	//mid=sum/2+(sum%2);
	while(l<r)
	{
		if(len[l]<len[r])
		{
			len[r]-=len[l];
			ans+=(c[l]!=c[r])*(len[l]);
			l++;
		}
		else
		{
			len[l]-=len[r];
			ans+=(c[l]!=c[r])*(len[r]);
			r--;
		}
	}
	//aabbc
	cout<<ans;
	
	//cout<<"\n";
	//for(int i=1;i<=n;i++)
	//	cout<<len[i]<<" "<<a[i]<<" "<<b[i]<<"\n";
/*
3
2 a
2 b
1 c
*/
	return 0;
}
