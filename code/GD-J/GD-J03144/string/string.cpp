#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2*1e5+10;
int a[N];
char c[N];
ll ans=0;
int t;
void turn(int i,int j,int n)
{
	if(i>j)
		return ;
	if(j<i)
		return ;
	if(i>t)
		return ;
	if(j<1)
		return ;
	if(i==j)
		return ;
	if(j<n/2)
	{
		turn(i,j,(i+j));
		return;
	}
	if(i>n/2)
	{
		turn(i,j,(i+j));
		return ;
	}
	if(c[i]!=c[j])
		ans+=min(a[i],a[j]);
	if(a[i]>a[j])
	{
		a[i]-=a[j];
		a[j]=0;
		j--;
	}
	else
		if(a[i]<a[j])
		{
			a[j]-=a[i];
			a[i]=0;
			i++;
		}
	else
		if(a[i]==a[j])
		{
			a[i]=0;
			a[j]=0;
			i++;
			j--;
		}
	turn(i,j,n);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	t=n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	turn(1,n,n);
	cout<<ans;
	return 0;
}
