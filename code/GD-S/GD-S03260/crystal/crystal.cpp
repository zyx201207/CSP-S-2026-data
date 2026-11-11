#include<bits/stdc++.h>
#define MAXN 500010
using namespace std;
typedef long long LL;
LL n,m,a[MAXN],tmp,res=1;
queue<LL>q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(LL i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	q.push(1);
	for(LL i=2;i<=n;i++)
	{
		LL minus=a[i]-a[i-1];
//		cout<<"i="<<i<<" minus="<<minus<<"\n";
		tmp+=minus*q.size();
		q.push(i);
//		cout<<"Now "<<q.front()<<"~"<<q.back()<<" tmp="<<tmp<<"\n";
		while(tmp>m)
		{
//			cout<<"Pop "<<q.front()<<"\n";
			LL x=q.front();
			q.pop();
			tmp-=a[i]-a[x];
		}
//		cout<<"And now "<<q.front()<<"~"<<q.back()<<" tmp="<<tmp<<"\n";
		res=max(res,(long long)q.size());
	}
	printf("%lld",res);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
