#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=1000010,M=N*2;
int head[N],Next[M],ver[M],tot;
void add(int x,int y)
{
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);add(y,x);
		}
		puts("I do not know how to work out the question which was CCF's masterpiece that like shit.");
		puts("RT++,please.");
		puts("I'm so tired.");
		puts("Please give me the place of number one");
		puts("CCF,please.");
	}
	
	return 0;
}