#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],t[500010];
int c[500010],ans=0,b[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=0;
		
		memset(b,-1,sizeof(b));
		for(int j=i;j<=n;j++)
		{
			
			if(b[a[j]]!=-1)
			{
				int f=ans;
				int k=b[a[j]];
				ans=ans-((ans-b[a[j]])+1);
				b[a[j]]=ans+1;
				ans++;
				for(int h=b[a[j]]+1;h<=f;h++)
				{
					b[c[h]]=-1;
				}c[ans]=a[j];
			}
			else{
				ans++;
				c[ans]=a[j];
				b[a[j]]=ans;
			}
//				for(int j=1;j<=ans;j++)
//			{
//				cout<<c[j]<<' ';
//				t[c[j]]++;
//			}
//			cout<<'\n';
			
		}
		for(int j=1;j<=ans;j++)
		{
//			cout<<c[j]<<' ';
			t[c[j]]++;
		}
//		cout<<'\n'<<"**********"<<'\n';
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<' ';
	}
	
	return 0;
}
