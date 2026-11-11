#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m;
int cards[500005];
long long cnt[300005];
bool hadcard[300005];//1~3e5
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin>>cards[i];
	for(int i=1;i<=n;i++)
	{
		memset(hadcard,0,sizeof(hadcard));
		int left=1;
		for(int j=i;j<=n;j++)
		{
			if(hadcard[cards[j]]) left=j;
			else hadcard[cards[j]]=true;
		}for(int j=max(i,left);j<=n;j++)
		{
			cnt[cards[j]] += hadcard[cards[j]];
			//cout<<cards[j]<<'|'<<cnt[cards[j]]<<' ';//
			//hadcard[j]=false;
		}
		//cout<<endl;//
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
