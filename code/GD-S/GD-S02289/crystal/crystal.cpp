#include<bits/stdc++.h> 
using namespace std;
struct node
{
	long long a,cha;
}num[500005];
bool cmp(node q,node p)
{
	return q.cha<p.cha;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i].a;
		ans+=num[i].a;
	}
	ans/=n;
	for(int i=1;i<=n;i++)
	{
		if(ans>num[i].a) num[i].cha=ans-num[i].a;
		else num[i].cha=num[i].a-ans;
		
	}
	sort(num+1,num+n+1,cmp);
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		if(num[i].cha>m)
		{
			break;
		}
		sum++;
		m-=num[i].cha;
	}
	cout<<sum<<endl;
	return 0;
}
