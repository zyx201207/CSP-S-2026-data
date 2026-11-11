#include<bits/stdc++.h>
using namespace std;
struct node
{
	string s;
	long long step;
	long long ij;
};
queue<node>q;
char l[1000000];
long long sl=0;
void bfs()
{
	node n={l,0,0};
	q.push(n);
	while(!q.empty())
	{
		node n=q.front();
		string zfc=n.s;
		long long cd=sl;
		bool flag=1;
		for(long long i=0;i<=cd;i++)
		{
			if(zfc[i]==zfc[cd-1-i])
			{
				
				continue;
				
			}
			else
			{
				flag=0;
				
				break;
			}
		}
		if(flag==1)
		{
			cout<<n.step;
			return;
		}
		char ls1;
		for(long long j=n.ij;j<cd;j++)
		{
			if(zfc[j]!=zfc[cd-1-j])
			{
				ls1=zfc[j];
				zfc[j]=zfc[cd-1-j];
				node xd={zfc,n.step+1,j+1};
				q.push(xd);
				zfc[j]=ls1;
			}
		}
		q.pop();
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long ls1;
	char ls2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ls1>>ls2;
		for(int k=1;k<=ls1;k++)
		{
			l[sl]=ls2;
			sl+=1;
		}
	}
	bfs();
	return 0;
}
