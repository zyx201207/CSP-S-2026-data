#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n,tocnt;
ll lim,k,tmp,ans;
deque<ll>q; 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%lld%lld",&n,&lim,&k);
		while(!q.empty())
			q.pop_front();
		q.push_back(k);
		n--;ans=0;tmp=0;
		while(n--)
		{
			scanf("%lld",&k);
			if(k-q.back()>lim)
			{
				while(!q.empty())
					q.pop_back();
				ans+=tmp;
				tmp=0;
			}
			else if(k-q.back()==lim)
			{
				q.push_back(k);
				tmp*=2;
			}
			else
			{
				tocnt=0;
				while(k-q.front()>lim)
				{
					//printf("pop:%lld when k=%lld,",q.front(),k);
					q.pop_front();
					tocnt++;
				}
				//printf("after pop:%lld,",q.front());
				//printf("que:%d,tot:%d\n",q.size(),tocnt);
				if(q.size()*tocnt==2)
					tmp++;
				q.push_back(k);
			}
		}
		printf("%d\n",ans+tmp);
	}
	return 0; 
}
