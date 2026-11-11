#include<bits/stdc++.h>
using namespace std;
struct card
{
	int number;
	card*next;
};
card back{0,nullptr};
card front{0,&back};
int a[500002];
int ans[300002];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i;i--)
	{
		const int ai=a[i];
		bool re=false;
		int cdnb;
		for(card*j=front.next;cdnb=j->number;j=j->next)
			ans[cdnb]++,
			re=re||(cdnb==ai);
		if(re)
		{
			card*j=front.next;
			for(;(cdnb=j->number)!=ai;j=j->next)
				ans[cdnb]--;
			front.next=j;
		}
		else
		{
			card*$=new card{ai,front.next};
			front.next=$;
			ans[ai]++;
		}
//		cerr<<i<<":\n";
//		for(card*j=front.next;cdnb=j->number;j=j->next)
//			cerr<<cdnb<<" ";
//		cerr<<"\n";
//		for(int i=1;i<=m;i++)
//			cerr<<ans[i]<<" ";
//		cerr<<"\n\n";
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
