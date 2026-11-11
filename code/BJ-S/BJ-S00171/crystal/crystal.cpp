#include <bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> a,last;

int giveAns(int index)
{
	long long energy=0;
	int ans=last[index]-index+1;
	for(int i=index-1;i>=1;i--)
	{
		energy+=a[index]-a[i];
		if(energy>m)
			break;
		ans++;
	}
	return ans;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.resize(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin()+1,a.end());
	last.resize(n+1); //last[i]为a[i]最后出现的位置
	last[n]=n;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]!=a[i+1])
			last[i]=i;
		else
			last[i]=last[i+1];
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,giveAns(i));
	cout<<ans<<endl;
	return 0;
}
