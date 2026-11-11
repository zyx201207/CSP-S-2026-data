#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500010];
int much[300010];
vector<int> desk;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			bool finded=0;
			long long drive=0;
			for(int w=0;w<(long long)desk.size();w++)
				if(desk[w]==a[j+1])
				{
					finded=1;
					drive=w;
					break;
				}
			if(finded==1)
			{
				drive=desk.size()-drive+1;
				while(drive--)
					desk.pop_back();
			}
			desk.push_back(a[j]);
		}
		for(int k=0;k<(long long)desk.size();k++)
			much[k]++;
		desk.clear();
	}
	for(int i=0;i<m;i++)cout<<much[i]<<" ";
	return 0;
} 
