#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,ans;
long long a[510000],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	for(int i=2 ; i<=n ; i++) 
	{
		int tmp=m,num=0;
		for(int j=i-1 ; j>=1 ; j--){
		if(tmp-abs((a[i]-a[j]))>=0)
		{
			tmp=tmp-abs((a[i]-a[j]));
			num++;
		}
		}
		if(num>ans)
			ans=num;
	}
		
	cout<<ans+1;
}
