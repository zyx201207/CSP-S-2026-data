#include<iostream>
#include<algorithm>
using namespace std;
long long lst[500005];
long long n,m;
bool check(long long mid)
{
	long long cnt=m;
	for(long long i=1;i<mid;i++)
	{
		cnt-=lst[mid]-lst[i];
		if(cnt<0)return false;
	}
	return true;
}
long long erfen()
{
	long long l=1,r=n+1;
	while(l+1<r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid;
		}
		else{
			r=mid;
		}
	}
	return l;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>lst[i];
	}
	sort(lst+1,lst+n+1);
	long long ans=erfen();
	while(lst[ans]==lst[ans+1]){
		ans+=1;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
