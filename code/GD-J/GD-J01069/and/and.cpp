#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx=-1,ans=1,b[200005],sum=0;
void jm()
{
	sum=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)
		{
			sum++;
			if(sum==1)ans=a[i];
			else ans=ans&a[i];
		}
	}
	if(sum!=m)return;
	maxx=max(maxx,ans);
}
void mj(int step)
{
	if(step>n)
	{
		jm();
		return;
	}
	b[step]=0;
	mj(step+1);
	b[step]=1;
	mj(step+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	mj(1);
	cout<<maxx;
	return 0;
} 

