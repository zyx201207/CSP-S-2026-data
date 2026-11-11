#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int NR=500005;
long long a[NR];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,i,j=1,t=0,ans=0;
	long long m,cnt=0;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		cnt+=1ll*t*(a[i]-a[i-1]); //t个元素，每个多了a[i]-a[i-1]
		while(cnt>m)
		{
			cnt-=a[i]-a[j];
			j++;
			t--;
		}
		t++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
