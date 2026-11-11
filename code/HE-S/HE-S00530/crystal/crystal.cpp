#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5e5+50;
long long m;
long long a[N];
bool oka=true;
bool okb=true;
vector <long long>v[N];
long long d;
int main()
{
	
	freopen("crystal.in()","r",stdin);
	freopen("crystal.out()","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
		{
			oka=false;
		}
	}
	if(oka)
	{
		long long cnt=0;
		long long ci=1;
		long long mm=m;
		while(mm>=ci)
		{
			if(mm>=ci)
			{
				mm-=ci;
				cnt++;
				ci++;
			}
		}
		cout<<cnt+1<<endl;
		return 0;
	}
	else
	{
		sort(a+1,a+1+n);
		long long dd=a[2]-a[1];
		bool ok=true;
		long long ci=1;
		long long cnt=1;
		long long kk=1;
		long long kkk=1;
		v[kk].push_back(1);
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1])
			{
				kkk++;
				v[kk].push_back(kkk);
			}
			else
			{
				kkk=1;
				kk++;
				v[kk].push_back(kkk);
				v[kk].end();
			}
		}
		long long ans=-2147483647;
		for(int i=1;i<=kk;i++)
		{
			ans=max(ans,v[i][v[i].size()-1] );
		}
		while(dd==0)
		{
			ci++;
			cnt++;
			dd=a[ci+1]-a[ci];
		//	cout<<dd<<" ";
		}
		long long mm=m;
		while(mm>=dd*ci)
		{
			mm=mm-dd*ci;
			ci++;
			cnt++;
			dd=a[ci+1]-a[ci];
		//	cout<<dd<<" ";
			while(dd==0)
			{
				ci++;
				cnt++;
				dd=a[ci+1]-a[ci];
			//	cout<<dd<<" ";
			}
		//	cout<<endl;
		}
		cout<<max(ans,cnt)<<endl;
		return 0;
	}
	return 0;
}
