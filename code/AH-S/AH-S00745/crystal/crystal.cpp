#include <bits/stdc++.h>
using namespace std;
int n;long long m;
long long sss[500005];
struct node{
	long long x;int num;long long nn;
}a[500005];
int a1;long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>sss[i];
	sort(sss+1,sss+1+n);
	for (int i=1;i<=n;i++)
	{
		if (i==1 || sss[i]!=sss[i-1])
		{
			a[++a1].x=sss[i];a[a1].num=a[a1].nn=1;
		}
		else a[a1].num++,a[a1].nn++;
	}
//	for (int i=1;i<=a1;i++) cout<<a[i].x<<' '<<a[i].num<<'\n';
	int l=1;long long sum=0,snum=a[1].num;
	ans=snum;
	for (int r=2;r<=a1;r++)
	{
		while (l<r && sum+(a[r].x-a[r-1].x)*snum>m)
		{
			sum-=(a[r-1].x-a[l].x)*a[l].nn;
			snum-=a[l].nn;
			a[l].nn=1ll*(m-sum-snum*(a[r].x-a[r-1].x))/(a[r].x-a[l].x);
			if (a[l].nn==0)
			{
				l++;continue;
			}
			sum+=a[l].nn*(a[r-1].x-a[l].x);
			snum+=a[l].nn;
			break;
		}
		if (sum+(a[r].x-a[r-1].x)*snum>m)
		{
			l=r;sum=0,snum=a[r].num;ans=max(ans,snum);
			continue;
		}
		sum+=(a[r].x-a[r-1].x)*snum;
		snum+=a[r].num;
		ans=max(ans,snum);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
