#include<iostream>
using namespace std;
int n,m;
int a[500005],b[500005],ans[500005],head=1,tail=1;
void put(int th)
{
	head=1;tail=1;
	int ret=tail-1;
	b[tail]=th;
	while(ret!=0)
	{
		if(b[ret]==th)head=tail;ret--;
	}
	for(int i=head;i<=tail;i++)
	{
		ans[b[i]]++;
	}
}
void game(int x)
{
	for(int i=x;i<=n;i++)
	{
		put(a[i]);
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		game(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]; 
	}
	return 0;
}
