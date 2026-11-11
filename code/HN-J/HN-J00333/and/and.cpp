#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans;
int a[200005];
string b[200005];
string add;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	int h=a[n],p=0;
	while(h!=0)
	{
		h/=2;
		p++;
	}
	for(int i=1;i<=n;i++)
	{
		int x=a[i],c=0;
		while(x!=0)
		{
			b[i]=char(x%2+'0')+b[i];
			x/=2;
			c++;
		}
		for(int j=1;j<=p-c;j++) b[i]='0'+b[i];
	}
	for(int i=0;i<=p-1;i++)
	{
		cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(b[j][i]=='1') cnt++;
		}
		if(cnt>=m)
		{
			add=add+'1';
			for(int j=1;j<=n;j++) 
			if(b[j][i]=='0') 
			{
				for(int k=0;k<=p-1;k++) b[j][k]='0';
			}
		}
		else add=add+'0';
	}
	for(int i=0;i<=p-1;i++)
	{
		ans=ans*2+add[i]-'0';
	}
	cout<<ans;
}
