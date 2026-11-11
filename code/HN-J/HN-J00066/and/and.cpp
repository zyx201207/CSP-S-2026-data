#include<bits/stdc++.h> 
using namespace std;
int n,m,a[200005],ans;
bool b[30][200005];
void f(int t,int l,int r)
{
	if(t==-1)return;
	int fi=0;
	for(int i=l;i<=r;i++)
	{
		fi+=b[t][i];
		a[i]-=b[t][i]<<t;
	}
	if(fi>=m)
	{
		ans+=1<<t;
		f(t-1,r-fi+1,r);
	}
	else
	{
		sort(a+l,a+r+1);
		for(int i=0;i<t;i++)
			for(int j=l;j<=r;j++)
				b[i][j]=a[j]&(1<<i);
		f(t-1,l,r);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<30;j++)
			b[j][i]=a[i]&(1<<j);
	f(29,1,n);
	cout<<ans;
	return 0;
}
