#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],tr[N],cnt1[N],cnt2[N],cnt[N],np[N];
int s[N];
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int k)
{
	for(int i=x;i<=n;i+=lowbit(i))  tr[i]+=k;
}
int query(int x)
{
	int sum=0;
	for(int i=x;i;i-=lowbit(i))  sum+=tr[i];
	return sum;  
}
set<int> mp[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	if(n<=20000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)  cnt[j]=np[j]=0;
			int top=0;
			for(int j=i;j<=n;j++)
			{
				if(cnt[a[j]]>0)  top=np[a[j]]-1;
				s[++top]=a[j];
				np[a[j]]=top;
				cnt[a[j]]=j;
			}  
			for(int j=1;j<=top;j++)  
			{
				cnt1[s[j]]++;
			}
		}
		for(int i=1;i<=m;i++)  cout<<cnt1[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)  
	{
		cnt1[a[i]]=i;
		mp[a[i]].insert(i);
	}
	for(int i=1;i<=n;i++)
	{
		auto it=mp[a[i]].upper_bound(i);
		it--;
		update(*it+1,-i);
		update(i,i);
	}
	for(int i=1;i<=n;i++)
	{
		cnt2[a[i]]=max(cnt2[a[i]],cnt1[i]+query(i));
	}
	for(int i=1;i<=m;i++)  cout<<cnt2[i]<<' ';
	return 0;
}
