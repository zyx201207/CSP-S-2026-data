#include<iostream>
#include<queue>
#include<algorithm>
#define endl '\n'
using namespace std;
long long  n,m,_m,a[500010];
long long now=0;
long long ans=0;
queue<long long> q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	_m=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	

	a[0]=a[1];
	for(int i=0;i<n;i++)
	{	
		int tmp=a[i+1]-a[i];
		now=(now+q.size()*tmp);
		q.push(a[i+1]);
		while(q.size()>1&&now>m)
		{
			long long maomao=q.front();
			q.pop();
			now-=(a[i+1]-maomao);
		}
		if(q.size()>ans)
		{
			ans=q.size();
		}
	}
	cout<<ans<<endl;
	return 0;
}

