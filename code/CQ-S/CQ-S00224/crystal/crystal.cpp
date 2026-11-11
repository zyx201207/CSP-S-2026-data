#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[500010];
int t[500010];
bool cmp(int a,int b)
{
	return a<b;
}
signed main()
{
	//greater
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	} 
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		t[i]=t[i-1]+a[i];
		//cout<<a[i]<<endl;
	}
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		long long l=i*a[i]-t[i];
		if(l<=m)
		{
			ans=i;
		//	cout<<a[i]<<" "<<t[i]<<" "<<l<<" "<<m<<endl;
			break;
		}
	}
//	cout<<(500000-315275+1)*a[500000]-(t[315275]-t[184724]);
//	cout<<a[313325]<<" "<<t[313325]<<" "<<313325*a[313325]-t[313325]<<endl;
//	cout<<a[315275]<<" "<<t[315275]<<" "<<315275*a[315275]-t[315275]<<endl;
	printf("%d",ans);
	return 0;
 } 
 //293238795
 //19883110
