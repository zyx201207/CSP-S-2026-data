#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long a[200005],f[200005];
vector<pair<char,long long>> vec;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	vec.push_back({'z',0});
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(i>1)
		{
			if(c[i]==c[i-1])
			{
				vec[pos].second+=a[i];
			}
			else
			{
				vec.push_back({c[i],a[i]});
				pos++;
			}
		}
		else
		{
			vec.push_back({c[i],a[i]});
			pos++;
		}
	}
	for(int i=1;i<vec.size();i++)
	{
		f[i]=f[i-1]+vec[i].second;
	}
	if(f[n]%2==0)
	{
		long long mid=f[vec.size()-1]/2;
		long long p=upper_bound(f+1,f+vec.size(),mid)-f;
		long long pos=mid+1,qjpos=p;
		long long ans=0;
		for(int i=p;i>=1;i--)
		{
			if(i==p)
			{
				long long l=mid-f[i-1],r=f[i]-mid;
				if(l<=r)
				{
					pos+=l;
				}
				else
				{
					long long lp=f[qjpos]+1,rp=pos+l-1;
					char jz=vec[i].first;
					qjpos++;
					for(;qjpos<vec.size();qjpos++)
					{
						if(f[qjpos-1]+1>=lp&&f[qjpos]<=rp)
						{
							if(vec[qjpos].first!=jz)
							{
								ans+=vec[qjpos].second;
							}
						}
						if(f[qjpos-1]+1>=lp&&f[qjpos]>rp)
						{
							if(vec[qjpos].first!=jz)
							{
								ans+=rp-f[qjpos-1];
							}
							break;
						}
						if(f[qjpos-1]+1>rp)
						{
							break;
						}
					}
					pos=rp+1;
				}
			}
			else
			{
				long long l=f[i]-f[i-1],r=f[qjpos]-pos+1;
				if(l<=r)
				{
					if(vec[i].first!=vec[qjpos].first)
					{
						ans+=l;
					}
					pos+=l;
				}
				else
				{
					long long lp=f[qjpos]+1,rp=pos+l-1;
					char jz=vec[i].first;
					for(;qjpos<vec.size();qjpos++)
					{
						if(f[qjpos-1]+1>=lp&&f[qjpos]<=rp)
						{
							if(vec[qjpos].first!=jz)
							{
								ans+=vec[qjpos].second;
							}
						}
						if(f[qjpos-1]+1>=lp&&f[qjpos]>rp)
						{
							if(vec[qjpos].first!=jz)
							{
								ans+=rp-f[qjpos-1];
							}
							break;
						}
						if(f[qjpos-1]+1>rp)
						{
							break;
						}
					}
					pos=rp+1;
				}
			}
		}
		cout<<ans;
	}
	if(f[n]%2==1)
	{
		long long mid=f[vec.size()-1]/2+1;
		long long p=upper_bound(f+1,f+vec.size(),mid)-f;
		long long pos=mid+1,qjpos=p;
		long long ans=0;
		for(int i=p;i>=1;i--)
		{
			if(i==p)
			{
				long long l=mid-1-f[i-1],r=f[i]-mid;
				if(l<=r)
				{
					pos+=l;
				}
				else
				{
					long long lp=f[qjpos]+1,rp=pos+l-1;
					char jz=vec[i].first;
					qjpos++;
					for(;qjpos<vec.size();qjpos++)
					{
						if(f[qjpos-1]+1>=lp&&f[qjpos]<=rp)
						{
							if(vec[qjpos].first!=jz)
							{
								ans+=vec[qjpos].second;
							}
						}
						if(f[qjpos-1]+1>=lp&&f[qjpos]>rp)
						{
							if(vec[qjpos].first!=jz)
							{
								ans+=rp-f[qjpos-1];
							}
							break;
						}
						if(f[qjpos-1]+1>rp)
						{
							break;
						}
					}
					pos=rp+1;
				}
			}
			else
			{
				long long l=f[i]-f[i-1],r=f[qjpos]-pos+1;
				if(l<=r)
				{
					if(vec[i].first!=vec[qjpos].first)
					{
						ans+=l;
					}
					pos+=l;
				}
				else
				{
					long long lp=f[qjpos]+1,rp=pos+l-1;
					char jz=vec[i].first;
					for(;qjpos<vec.size();qjpos++)
					{
						if(f[qjpos-1]+1>=lp&&f[qjpos]<=rp)
						{
							if(vec[qjpos].first!=jz)
							{
								ans+=vec[qjpos].second;
							}
						}
						if(f[qjpos-1]+1>=lp&&f[qjpos]>rp)
						{
							if(vec[qjpos].first!=jz)
							{
								ans+=rp-f[qjpos-1];
							}
							break;
						}
						if(f[qjpos-1]+1>rp)
						{
							break;
						}
					}
					pos=rp+1;
				}
			}
		}
		cout<<ans;
	}
	return 0;
} 
