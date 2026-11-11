#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx=-1,a[100005],c[100005];
void f(int x,int y)
{
	if(y==m)
	{
		long long p,q;
		for(int i=1;i<=n;i++)
			if(c[i]==1)
			{
				p=a[i];
				q=i+1;
				break;
			}
		for(int i=q;i<=n;i++)if(c[i]==1)p=p&a[i];
		maxx=max(maxx,p);
		return;
	}
	for(int i=x;i<=n;i++)
	{
		c[i]=1;
		f(i+1,y+1);
		c[i]=0;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	f(1,0);
	cout<<maxx;
	return 0;
} 
