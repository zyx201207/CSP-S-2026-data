#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N];
int sum;
char c[N];
bool flag=1;
struct node
{
	int l,r;
	char ch;
};
node p[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(a[i]>500)
		{
			flag=0;
		}
		p[i]={l,l+a[i]-1,c[i]};
		l+=a[i];
		sum+=a[i];
	}
	if(flag)
	{
		string str;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				str+=c[i];
			}
		}
		int m=str.size(),cnt=0;
		str=' '+str;
		for(int i=1;i<=m;i++)
		{
			if(str[i]!=str[m-i+1])
			{
				cnt++;
				str[m-i+1]=str[i];
			}
		}
		cout<<cnt<<endl;
		return 0;
	}
	
	int m=(sum+1ll)/2,ans=0;
	for(int i=n;i>=1;i--)
	{
		int l=sum-p[i].l+1,r=sum-p[i].r+1;
		if(p[i].l<=m&&p[i].r<=m)
		{
			break;
		}
		int l1=1,r1=i;
		while(l1<r1)
		{
			int mid=(l1+r1+1)/2;
			if(p[mid].l<=l)
			{
				l1=mid;
			}
			else
			{
				r1=mid-1;
			}
		}
		if(l>=p[i].l&&r<=p[i].r)
		{
			l1=i;
		}
		int l2=1,r2=i-1; 
		while(l2<r2)
		{
			int mid=(l2+r2+1)/2;
			if(p[mid].l<=r)
			{
				l2=mid;
			}
			else
			{
				r2=mid-1;
			}
		}
		int cnt=p[i].r-p[i].l+1;
		for(int j=l2;j<=l1;j++)
		{
			if(p[j].ch==p[i].ch)
			{
				if(j==l1)
				{
					cnt-=l-p[j].l+1;
					continue;
				}
				if(j==l2)
				{
					cnt-=p[j].r-r+1;
					continue;
				}
				cnt-=p[j].r-p[j].l+1;
			}
		}
		ans+=cnt;
	}
	cout<<ans<<endl;
	return 0;
}
