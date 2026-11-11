#include<iostream>
#include<queue>
using namespace std;
int a[5005];
int b[5005];
int c[5005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	for(int i=1; i<=n; i++)
	{
		queue<int>q;
		for(int j=i; j<=n; j++)
		{
			if(b[a[j]]!=0)
			{
				int r=false;
				int aaa=q.size();
				for(int k=0; k<=aaa; k++)
				{
					int ddrty;
					if((q.front())==a[j])
					{
						r=true;
						q.pop();
					}
					if(r==true)
					{
						int si=aaa-k;
//						si-=2;
						while(si--)
						{
							int qq=q.front();
							b[qq]=0;
							if(q.size()>0)
							{
								q.pop();
							}
						}
						break;
					}
					else
					{
						int aa=q.front();
						q.pop();
						q.push(aa);
					}
				}
			}
			q.push(a[j]);
			b[a[j]]++;
//			cout<<endl;
		}
		for(int j=0; j<q.size(); j++)
		{
//			cout<<q.front()<<" ";
			c[q.front()]++;
			q.pop();
		}
	}
	for(int i=1; i<=m; i++)
	{
		cout<<c[a[i]]<<" ";
	}
	return 0;
}
