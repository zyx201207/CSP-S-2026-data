#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000009];
long long cxy(long long tp,long long c,long long num,long long yw)
{
	if(tp-1==0) return num;
	if(c==0) return num;
	if(c-(a[yw]-a[tp])<0) return num;
//	if(wei-1>=1)
	if(c>0)
	cxy(tp-1,c-(a[yw]-a[tp]),num+1,yw);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	long long sum=m;
	long long maxx=-0x7fffffff;
//	for(long long i=1;i<=n;i++) cout<<a[i]<<" ";
	for(long long i=n;i>=1;i--)
	{
//		cout<<maxx<<" ";
		maxx=max(cxy(i,m,1,i),maxx);
		if(maxx>i)
		{
			cout<<maxx<<endl;
			return 0;
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
