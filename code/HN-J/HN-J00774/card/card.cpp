#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,a[200005],b[200005];
map<int,int>mp,mp2;
int maxx=INT_MIN;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	int p=0;
	int len=n;
	int j=0;
	for(int p=1;p<=len;p++)
	{
		for(int i=p+1;i<=n;i++)
		{
			j++;
			if(mp[a[i]]==1)
			{
				while(j--)
				{
					
					if(b[j]==a[i])
					break;
					b[j]=0;
					mp[b[j]]=0;
				}
			}
			b[j]=a[i];
			mp[a[i]]=1;
//			cout<<j<<endl;
		}
		for(int i=1;i<=j;i++)
		{
			mp2[b[i]]++;
//			cout<<b[i]<<" ";
		}
//		cout<<endl;
		p++;
//		cout<<p<<'/'<<len;
	}
	for(int i=1;i<=maxx;i++)
	{
		if(mp2[i]!=0)
		cout<<mp2[i]<<" ";
	}
	return 0;
}

