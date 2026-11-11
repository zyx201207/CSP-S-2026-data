#include <bits/stdc++.h>
using namespace std;

int n,m;
int num[500005];
int las[500005];
int sum[500005];

struct node
{
	int a,b;
} nus[500005],gh[500005];
int nusl;
int nut[500005];

void add(int a,int b)
{
	nus[++ nusl] = {b,nut[a]};
	nut[a] = nusl;
}

bool cmp(node a,node b)
{
	return a.b < b.b;
}

int main()
{
		freopen("card.in","r",stdin);
		freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i ++) scanf("%d",&num[i]);
	for (int i = 1;i <= n;i ++) las[num[i]] = i;
	for (int i = 1;i <= m;i ++) gh[i].a = i;
	for (int i = 1;i <= m;i ++) 
	{
		if (las[i] + 1 <= n) 
		{
			add(i,num[las[i] + 1]);
			gh[num[las[i] + 1]].b ++;
		//	cout << i << " " << num[las[i] + 1] << endl;
		}else
		{
			add(i,0);
			gh[0].b ++;
		}
	}
//	for (int i = 1;i <= m;i ++) cout << gh[i].b << endl;
	sort(gh + 1,gh + m + 1,cmp);
	
	for (int i = 1;i <= n;i ++) sum[num[i]] ++;
	
	for (int i = 1;i <= m;i ++)
		for (int f = nut[gh[i].a];f;f = nus[f].b)
		{
			sum[nus[f].a] += sum[gh[i].a];
		//	cout << gh[i].a << " " << nus[f].a << endl;
		}
			
	
	for (int i = 1;i <= m;i ++) printf("%d ",sum[i]);
	return 0;
}

/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

*/
