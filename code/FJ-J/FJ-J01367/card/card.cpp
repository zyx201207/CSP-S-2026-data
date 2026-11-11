#include<iostream>
#include<stack>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],ans[N];
bool k[N];
stack<int>s;
void re()
{
	for(int i=1;i<=m;i++)
	{
		k[i]=false;
	}
	while(!s.empty())
	{
		ans[s.top()]++;
		s.pop();
	}
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//have[a[i]]=true;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(k[a[j]])
			{
				while(s.top()!=a[j])
				{
					s.pop();
				}
			}else
			{
				k[a[j]]=true;
				s.push(a[j]);
			}
		}
		re();
	}
	for(int i=1;i<=m;i++)
	{
		//if(have[i])
		cout<<ans[i]<<' ';
	}
	return 0;
}//very good
