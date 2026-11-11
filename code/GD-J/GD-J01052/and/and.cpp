#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],t[100],x,y,yy=1,s1,s2,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	t[1]=1;
	for(int i=2;i<=31;i++) t[i]=t[i-1]*2;
	sort(a+1,a+1+n);
	for(int i=n;i>=n-m+1;i--)
	{
		x++;
		for(int j=30;j>=1;j--)
		{
			if(t[j]<=a[i]) a[i]-=t[j],b[x]*=10,b[x]+=1;
			else b[x]*=10;
		}
	}
	s1=b[1];
	for(int i=2;i<=m;i++)
	{
		yy=1;
		while(b[i]>0)
		{
			if(s1%10==1&&b[i]%10==1) s2+=yy;
			s1/=10,b[i]/=10;yy*=10;
		}
		s1=s2,s2=0;
	}
	while(s1>0)
	{
		y++;
		if(s1%10==1) s+=t[y];
		s1/=10;
	}
	cout<<s;
	return 0;
}
