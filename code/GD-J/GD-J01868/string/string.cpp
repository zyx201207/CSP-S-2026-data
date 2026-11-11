#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long cnt;
	char c;
};
long long n;
vector<node>a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long tot=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		long long x;
		char ch;
		scanf("%lld",&x);
		cin>>ch;
		a.push_back({x,ch});
		tot+=x;
	}
	long long sum=0,f=tot/2;
	for(int i=0;i<n;i++)
	{
		sum+=a[i].cnt;
		if(sum==f)
		{
			if(tot%2==1)
				a[i+1].cnt--;
			break;
		}
		if(sum>f)
		{
			a.insert(a.begin()+i+1,node{sum-f-(tot%2==1),a[i].c});//
			a[i].cnt-=sum-f;
			break;
		}
	}
	long long l=0,r=a.size()-1,ans=0;
	while(l<=r)
	{
		if(a[l].cnt<a[r].cnt)
		{
			if(a[l].c!=a[r].c)
				ans+=a[l].cnt;
			a[r].cnt-=a[l].cnt;
			l++;
		}
		else if(a[l].cnt>a[r].cnt)
		{
			if(a[l].c!=a[r].c)
				ans+=a[r].cnt;
			a[l].cnt-=a[r].cnt;
			r--;
		}
		else
		{
			if(a[l].c!=a[r].c)
				ans+=a[l].cnt;
			a[l].cnt=a[r].cnt=0;
			l++;
			r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
