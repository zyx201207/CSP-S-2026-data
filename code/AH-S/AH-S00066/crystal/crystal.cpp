#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long c[500005];
struct node
{
	int g; 
	long long na; 
}v[500005];
int ans,t;
int mm;
long long s;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	sort(a+1,a+n+1);
	long long aa=0;
	for(int i=1;i<=n;i++)
	{
		if(aa!=a[i])
		{
			v[++t].g=a[i];
			v[t].na=1;
			aa=a[i];
		}
		else v[t].na++;
	}
	for(int i=2;i<=t;i++)
	{
		s=0;
		mm=v[i].na;
		for(int j=i-1;j>=0;j--)
		{
			if(s+v[j].na*(v[i].g-v[j].g)<=m)
			{
				s+=v[j].na*(v[i].g-v[j].g);
				mm+=v[j].na;
				if(s==m) break;
			}
			else 
			{
				mm+=(m-s)/(v[i].g-v[j].g);
				break;
			}
		}
		ans=max(ans,mm);
	} 
	cout<<ans;
	return 0;
}
