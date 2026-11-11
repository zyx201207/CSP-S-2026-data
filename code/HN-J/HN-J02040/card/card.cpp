#include<bits/stdc++.h>
using namespace std;
struct jg
{
	bool x;
	int p;
};
int n,m;
int a[500010],ans[500010];
jg val[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i;i--)
	{
		if(val[a[i]].x==1)
		{
			for(int j=i;j<val[a[i]].p;j++)
				val[a[j]]={0,0};
			for(int j=val[a[i]].p;j<=n;j++)
				ans[a[j]]+=val[a[j]].x;
		}
		else
		{
			val[a[i]].x=1,val[a[i]].p=i;
			for(int j=i;j<=n;j++)
				ans[a[j]]+=val[a[j]].x;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' '; 
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1

