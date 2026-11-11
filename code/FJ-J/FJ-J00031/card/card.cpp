#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=200001;
int n,m;
int a[N];
int tong[N];
int ans[N];
inline long long read()
{
	long long f=1,x=0;
	char c;
	c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
			f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
void solve1(int t)
{
	vector<int> v;
	bool in_stk[N]={false};
	for(int i=t;i<=n;i++)
	{
		
		if(in_stk[a[i]])
		{
			while(!v.empty()&&v.back()!=a[i])
			{
				in_stk[v.back()]=false;
				v.pop_back();
			}
			if(!v.empty())
				v.pop_back();
			v.push_back(a[i]);
		}
		else
		{
			in_stk[a[i]]=true;
			v.push_back(a[i]);
		}
		/*for(int i=0;i<v.size();i++)
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;*/
	}
	for(int i=0;i<v.size();i++)
	{
		ans[v[i]]++;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		tong[a[i]]++;
	}
	for(int i=1;i<=n;i++)
		solve1(i);
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	
} 
