#include<bits/stdc++.h> 
using namespace std;
long long m,a[500005],q[500005],ans,maxn,num;
int n;
long long suiji(int u,int v)
{
	return rand()%(v-u+1)+u;
}
void qsort(int x,int y)
{
	if(x>=y) return;
	int l=x,r=y,mid=a[suiji(x,y)];
	while(l<=r)
	{
		while(a[l]<mid) l++;
		while(mid<a[r]) r--;
		if(l<=r)
		{
			swap(a[l],a[r]);
			l++,r--;
		}
	}
	qsort(x,r);
	qsort(l,y);
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	qsort(1,n);
	for(int i=1;i<=n;i++)
	{
		ans=0;
		num=0;
		for(int j=i;j>=1;j--)
		{
			ans+=a[i]-a[j];
			if(ans>m)
			{
				break;
			}
			num++;
		}
		maxn=max(maxn,num);
	}
	cout<<maxn;
	return 0;
}
