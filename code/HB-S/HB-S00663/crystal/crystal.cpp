#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
int a[500005];

int diff[500005];
int minn=LLONG_MAX;

map<int,int> mapp;

signed main()
{
	//cout<<(long long)(500000*1000000000000);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	//cout<<n<<" "<<m<<endl;
	
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		//cout<<a[i]<<" ";
		diff[i]=diff[i-1]+(a[i]-a[i-1])*(i-1);
		mapp[diff[i]]=a[i];
	}
	//for(auto &it:mapp)
	//{
		//cout<<it.first<<" "<<it.second<<endl;
	//}
	
	int l;
	for(l=1;l<=n;++l)
	{
		if(diff[l]>m) break;
	}
	printf("%lld",l-1);
	//cout<<find_()<<endl;
}
