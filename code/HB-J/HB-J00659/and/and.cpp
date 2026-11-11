#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool id[35][200005];
void ch(int x,int t)
{
	int i=1;
	int tx=x;
	while(tx)
	{
		if(tx%2) id[i][t]=1;
		tx/=2;
		i++;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ch(a[i],i);
	}
	int flag=0,ans=0;
	string cmp;
	int book[200005]={};
	for(int i=30;i>=1;i--)
	{
		int cnt=0;
		string s="";
		int bookt[200005]={};
		for(int j=1;j<=n;j++) 
		{
			if(!id[i][j]) continue;
			if(flag&&bookt[j]+1<=book[j])
				s=s+char(j),cnt++,bookt[j]++;
			else if(!flag) cnt++,s=s+char(j);
		}
		if(cnt<m) continue;
		sort(s.begin(),s.end());
		if(!flag) 
		{
			flag=1;
			ans+=pow(2,i-1),cmp=s;
			for(int j=0;j<cnt;j++) book[int(s[j])]++;
		}
		else cmp=s,ans+=pow(2,i-1);
	}
	cout<<ans;
	return 0;
}
