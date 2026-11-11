#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N int(5e5+10)
using namespace std;

ll n,a[N];
ull ret,m;

//special
bool flag=1;
ll num;

void check()
{
	printf("--------------------\n");
	for(int times=0;times<n;++times)
		printf("%d ",a[times]);
	printf("\n--------------------\n");
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int times=0;times<n;++times)
	{
		scanf("%lld",a+times);
		if(times==1) num=a[times]-a[times-1];
		if(num!=0 && a[times]-a[times-1]!=num)
			flag=0;
	}
	
	
	//special
	if(flag)
	{
		ll cnt=1;
		num=abs(num);
		while(cnt*(num+cnt*num)/2<m) ++cnt;
		printf("%lld",cnt);
		return 0;
	}
	
	
	sort(a,a+n);
//	check();
	
	for(int times1=1;times1<n;++times1)
	{
		ull cpym=m;
		ull ans=1;
		for(int times2=times1-1;times2>=0;--times2)
		{
			const int tmp=a[times1]-a[times2];
			if(cpym<tmp) break;
			cpym-=tmp;
			++ans;
		}
		ret=(ret>ans?ret:ans);
	}
	printf("%lld",ret);
	return 0;
}
