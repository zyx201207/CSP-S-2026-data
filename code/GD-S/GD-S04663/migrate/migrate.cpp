#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int a[2000010];
pair<int,int>s[2000010];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int fw,T,n,D;
	cin>>fw>>T;
	while(T--)
	{
		cin>>n>>D;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(fw==11||fw==12)
		{
			if(n==1)
				cout<<"0\n";
			else
			{
				int po=D/(a[2]-a[1]);
				if(po<=1||po*2>n)
					cout<<"0\n";
				else
					cout<<n-po*2+1<<'\n';
			}
			continue;
		}
		if(fw==13||fw==14)
		{
			int b=0;
			for(int i=1;i<=n;i++)
				if(a[n]-a[i]<=D)
				{
					b=i;
					break;					
				}
			int q=0,w=0,e=0,r=0;
			for(int i=1,j=1;i<b;i++)
			{
				for(;j<=n&&a[j]-a[i]<=D;j++);
				if(j==b+1)
					q++;
				if(j==b+2)
					w++;
			}
			for(int i=n,j=n;i>b;i--)
			{
				for(;j>=1&&a[i]-a[j]<=D;j--);
				if(j==b-1)
					e++;
				if(j==b-2)
					r++;
			}
			cout<<q*r+w*e<<'\n';
			continue;
		}
		int t=0;
		for(int i=n;i>1;i--)
		{
			s[i]={0,1};
			for(int j=i-1,k=i,o=1;j>=1;j--)
			{
				for(;k>=1&&a[k]-a[j]>D;o-=s[k].second,k--);
				if(k==j)
					break;
				s[j].first=s[k].first+1;
				if(s[j].first!=s[j+1].first)
				{
					o=0;
					for(int u=k;u>j&&s[u].first==s[k].first;u--)
						o+=s[u].second;
				}
				s[j].second=o;
				if(s[j].second==2)
					t++,cout<<j<<' '<<i<<'\n';
			}
		}
		cout<<t<<'\n';
	}
	return 0;
}

