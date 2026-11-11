#include<iostream>
#include<algorithm>
using namespace std;
int n,ans=1;
long long a[500005],maxn,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int s=n/2;
	for(int i=s;i>=1;i--)
	{
		int x=a[i+1]-a[i];
		if(m-x>=0)
		{
			m-=x;
			a[i]+=x;
			ans++;
		}
	}
	maxn=a[s++];
	while(m>0&&s<n)
	{
		for(;a[s-1]>=maxn;s++)
		{
			if(a[s]>maxn) maxn=a[s];
			else ans++;
		}
		m-=s-1;
		a[s-1]++;
		if(a[s-1]==maxn) ans++;
	}
	//cout<<s<<endl;
	if(s<=n&&a[s]==a[++s]&&s>n/2) ans++;
	cout<</*maxn<<" "<<*/ans;
}
