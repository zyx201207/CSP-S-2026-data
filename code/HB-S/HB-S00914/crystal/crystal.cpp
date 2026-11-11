#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n;
long long m;
long long a[maxn];
long long op;
int ans;
int tmp=1;
void func(int x,int basic)
{
	for(int i=x;i>=1&&op>0;i--)
	{
		int temp=basic-a[i];
		if(op-temp>=0)
			tmp++,op-=temp;
		else
			break;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(m==0)
	{
		int tmp=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1])
				tmp++;
			else
				tmp=1;
			ans=max(ans,tmp);
		}
	}
	else
	{
		int c[maxn];
		for(int i=1;i<=n;i++)
			c[i]=a[i]-a[i-1];
		op=m;
		for(int i=n;i>=1&&i-tmp>0;i--)
		{
			if(tmp>1)
				op+=c[i+1]*(tmp-1);
			if(i<n)
				tmp--;
			func(i-tmp,a[i]);
			ans=max(ans,tmp);
		}
	}
	cout<<ans<<endl;
	return 0;
}
