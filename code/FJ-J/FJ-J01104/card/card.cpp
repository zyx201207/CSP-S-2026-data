#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],cnt[500005];
bool f[500005];
int b[500005];

void play(int begin)
{
	int cur=1;
	memset(f,0,sizeof(f));
	memset(b,0,sizeof(b));
	for(int i=begin;i<=n;i++)
	{
		if(f[a[i]])
		{
			for(int j=cur;j>=1;j--)
			{
				b[j]=0;
				cur--;
				if(b[j]==a[i])break;
			}
			cur=1;
		}
		//cout<<b[cur]<<endl;
		b[cur++]=a[i];
		//cout<<b[cur]<<endl;
		f[a[i]]=1;
	}
	for(int i=1;i<=cur;i++)
	{
		cnt[b[i]]++;
	} 
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		play(i);
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
