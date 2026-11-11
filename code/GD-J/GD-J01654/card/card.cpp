#include<iostream>

using namespace std;
struct sb{
	long long last,next,now;
};
long long n,m;
long long a[500005];
sb mp[500005];
long long ans[500005];
void f(long long pos)
{
	if(pos>n) return ;
	
	for(int i=mp[0].next;i<pos;)
	{
		if(mp[i].now==mp[pos].now)
		{
			mp[mp[i].last].next=pos;
			mp[pos].last=mp[i].last;
		}
		i=mp[i].next;
	}
	f(pos+1);
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
		mp[0].next=i;
		for(int j=1;j<=n;j++)
		{
			mp[j].now=a[j];
			mp[j].last=j-1;
			mp[j].next=j+1;
		}
		f(i);
		for(int j=mp[0].next;j<=n;)
		{
			ans[mp[j].now]++;
			j=mp[j].last;
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
}
