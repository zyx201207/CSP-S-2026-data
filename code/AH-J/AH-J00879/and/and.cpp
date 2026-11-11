#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
bool a[200005][35],flog[200005];
int l;
ll x[200005],f[35],s=0;
int n,m;
bool cmp(ll xx,ll yy)
{
	return xx>yy;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	sort(x+1,x+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		l=-1;
		while(x[i]>0)
		{
			a[i][++l]=x[i]%2;
			x[i]/=2;
			if(a[i][l]==1) f[l]++;
		}
	}
	for(int i=30;i>=0;i--)
	{
		if(f[i]>=(ll(m)))
		{
			ll st=1;
			for(int j=1;j<=i;j++)
				st*=2;
			s+=st;
			for(int j=1;j<=n;j++)
			{
				if(a[j][i]==0&&flog[j]==0)
				{
					flog[j]=1;
					for(int k=i-1;k>=0;k--)
					{
						if(a[j][k]==1)
						{
							f[k]--;
						}
					}
				}
			}
		}
	}
	cout<<s<<endl;
	return 0;
}
