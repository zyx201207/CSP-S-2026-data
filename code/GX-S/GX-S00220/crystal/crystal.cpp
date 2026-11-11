#include<bits/stdc++.h>
using namespace std;
int n,head=1,lain=1,ans;
long long m,a[500010],cnt,cha;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		cnt+=a[i];
		cha=((i-head+1)*a[i])-cnt;
		while(m<cha)
		{
			cnt-=a[head];
			head++;
			cha=((i-head+1)*a[i])-cnt;
		}
		if(ans<=lain-head+1)
		{
			ans=lain-head+1;
			lain++;
		}else
		{
			cout<<ans;
			break;
		}
	}
	return 0;
}
