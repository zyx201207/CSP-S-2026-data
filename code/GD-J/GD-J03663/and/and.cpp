#include <bits/stdc++.h>
using namespace std;
struct mj{
	long long vlu;
	long long m;
	string s;
}a[200100];
bool cmp(mj x,mj y)
{
	return x.vlu<y.vlu;
}
bool cmp2(mj x,mj y)
{
	return x.m>y.m;
}

int wei(mj x,mj y)
{
	long long q;
	long long size_1=max(x.s.size(),y.s.size());
	if(x.s.size()<y.s.size())
	{
		string s_;
		long long differ=y.s.size()-x.s.size();
		while(differ--)
		{
			s_+='0';
		}
		s_+=x.s;
		x.s=s_;
	}
	else{
		string s_;
		long long differ=x.s.size()-y.s.size();
		while(differ--)
		{
			s_+='0';
		}
		s_+=y.s;
		y.s=s_;
	}
	reverse(x.s.begin(),x.s.end());
	reverse(y.s.begin(),y.s.end());
	for(int i=0;i<size_1;i++)
	{
		if(x.s[i]==1 && y.s[i]==1)
		{
			q+=pow(2,i);
		}
	}
	return q;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].vlu;
	}
	sort(a+1,a+n+1,cmp);
	if(m==1)
	{
		cout<<a[n].vlu;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		while(a[i].vlu)
		{
			a[i].s+=a[i].vlu%2;
			a[i].vlu/=2;
		}
		reverse(a[i].s.begin(),a[i].s.end());
	}
	while(m--)
	{
		for(int i=1;i<=n;i++)
			{	
				long long mAx_=-1;
				for(int j=1;j<=n;j++)
				{
					long long z=wei(a[i], a[j]);
					if(j!=i)mAx_=max(mAx_,z);
				}
				a[i].m=mAx_;
			}	
	}
	sort(a+1,a+n+1,cmp2);
	cout<<a[1].m;
	return 0;
} 
