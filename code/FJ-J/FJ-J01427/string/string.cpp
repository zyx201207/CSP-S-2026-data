#include<iostream>
#include<vector>
using namespace std;
int n;
long long ans,sum;
struct zifu
{
	long long cnt;
	char c;
}s[200005];
vector<zifu>v1,v2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].cnt>>s[i].c;
		sum+=s[i].cnt;
	}
	long long now=0;
	for(int i=1;i<=n;i++)
	{
		if(now+s[i].cnt>=(sum+1)/2)
		{
			if(sum&1)
				s[i].cnt++,sum++;
			if(sum/2-now)
				v1.push_back({sum/2-now,s[i].c});
			for(int j=n;j>i;j--)
				v2.push_back(s[j]);
			if(s[i].cnt-(sum/2-now))
				v2.push_back({s[i].cnt-(sum/2-now),s[i].c});
			break;
		}
		else
			v1.push_back(s[i]),now+=s[i].cnt;
	}
	auto it1=v1.begin(),it2=v2.begin();
	while(1)
	{
		if(it1==v1.end()&&it2==v2.end())
			break;
		long long res=min(it1->cnt,it2->cnt);
		it1->cnt-=res,it2->cnt-=res;
		if(it1->c!=it2->c)
			ans+=res;
		if(it1->cnt==0)
			it1++;
		if(it2->cnt==0)
			it2++;			
	}
	cout<<ans;
	return 0;
}
