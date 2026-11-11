#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,max_=1;
	scanf("%lld%lld",&n,&m);
	vector<long long> zl;
	map<long long,long long> mli;
	for(long long f=0,a;f<n;f++)
	{
		scanf("%lld",&a);
		mli[a]++;
		if(mli[a]==1)
			zl.push_back(a);
	}
	sort(zl.begin(),zl.end());
	long long xb=0,fm;
	for(long long f=zl[0],zh;f<=zl[zl.size()-1];f++)
	{
		zh=mli[f];
		if(f==zl[xb+1])
			xb++;
		fm=m;
		for(long long o=xb-1,bl=zl[xb]-zl[o];o>=0&&bl<=fm;o--,bl=zl[xb]-zl[o])
		{
			if(mli[zl[o]]*bl<=fm)
			{
				fm-=mli[zl[o]]*bl;
				zh+=mli[zl[o]];
			}
			else
			{
				zh+=fm/bl;
				fm=0;
			}
		}
		max_=max(max_,zh);
	}
	printf("%lld",max_);
	return 0;
}
