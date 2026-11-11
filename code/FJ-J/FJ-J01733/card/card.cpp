#include<bits/stdc++.h>
using namespace std;
int f[100010],a[100010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)//Ä£Äâ  
	{
		stack<int> s;
		bool v[100010];
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++)
		{
			if(!v[a[j]]) {s.push(a[j]);v[a[j]]=1;}
			else {while(s.top()!=a[j]){v[s.top()]=0;s.pop();}}
		}
		for(int i=1;i<=m;i++)
			if(v[i])f[i]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",f[i]);
	return 0;
}
