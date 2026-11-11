#include<bits/stdc++.h>
int n,l,r,mid,ans;
long long m,sl[500005],tmp[500005];
void gsort(int x,int y)
{
	if(x>=y)
	{
		return;
	}
	int top=x-1,mid=(x+y)/2,l=x,r=mid+1;
	gsort(x,mid);
	gsort(mid+1,y);
	while(l<=mid&&r<=y)
	{
		if(sl[l]<=sl[r])
		{
			top++;
			tmp[top]=sl[l];
			l++;
		}
		else
		{
			top++;
			tmp[top]=sl[r];
			r++; 
		}
	}
	while(l<=mid)
	{
		top++;
		tmp[top]=sl[l];
		l++;
	}
	while(r<=y)
	{
		top++;
		tmp[top]=sl[r];
		r++;
	}
	for(int i=x;i<=y;i++)
	{
		sl[i]=tmp[i];
	}
	return;
}
int check(int x)
{
	long long totol=0,mintotol;
	for(int i=1;i<=x;i++)
	{
		totol+=sl[x]-sl[i];
	}
	mintotol=totol;
	for(int i=x+1;i<=n;i++)
	{
		totol-=sl[i-1]-sl[i-x];
		totol+=(sl[i]-sl[i-1])*x;
		mintotol=std::min(totol,mintotol);
	}
	//printf("%d %d\n",x,totol);
	return mintotol<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&sl[i]);
	}
	gsort(1,n);
	//std::sort(sl+1,sl+n+1);
	l=1;
	r=n;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)==1)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%d",ans);
	return 0;
}
