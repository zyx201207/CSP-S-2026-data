#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

const int N=5e5+10;
int n,m,a[N],v[N],ans[N];
stack<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];	
	int t=n,k;
	while(t)
	{
		memset(v,0,sizeof(v));
		
		k=n-t+1;
		while(k<=n)
		{
			if(v[a[k]])
			{
				while(s.top()!=a[k])
					s.pop();
				if(s.top()==a[k])
					s.pop();
			}
			s.push(a[k]);
			v[a[k]]=1;
			++k;
		}
		while(!s.empty())
		{
			++ans[s.top()];
			s.pop();
		}
		--t;
	}
	for(int i=1;i<=m;++i)
		cout<<ans[i]<<" ";

	fclose(stdin);
	fclose(stdout);	
	return 0;
}
