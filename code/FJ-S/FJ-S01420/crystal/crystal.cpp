#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int n;
long long m;
int ans=0;
map<long long,int>mp;
bool check(int x)
{
	long long sum=m;
	int res=0;
	int pos=upper_bound(a+1,a+1+n,a[x])-a;
	for(int i=pos-1;i>=1;i--)
	{
		if(a[i]>a[x]) continue;
		if(sum>=a[x]-a[i])
		{
			sum-=a[x]-a[i];
			res++;
		}
		else break;
	}
	if(ans<=res)
	{
		ans=res;
		return true;
	}
	else return false;
}
bool checkA()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i) return false;
	}
	return true;
}
void solveA()
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return;
}
bool checkB()
{
	long long d=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=d) return false; 
	}
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{                    
		scanf("%lld",&a[i]);
	}
	if(checkA())
	{
		solveA();
		return 0;
	}
	if(checkB())
	{
		solveA();
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(mp[a[i]]!=0) continue;
		check(i);
		mp[a[i]]=ans;
		long long x=a[i];
		i=upper_bound(a+1,a+1+n,x)-a;
		i--;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
