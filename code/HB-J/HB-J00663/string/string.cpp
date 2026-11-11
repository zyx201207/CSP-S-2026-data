#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	vector <pair<int,char> > d(n+1,{0,' '});
	for (int i=0;i<n;i++)
	{
		scanf("%d",&d[i].first);
		getchar();
		d[i].second=getchar();
	}
	int l=0,r=n-1;
	long long sum=0;
	while (l<r && l<n && r>=0)
	{
		if (d[l].second!=d[r].second)
		{
			if (d[l].first==d[r].first)
				sum+=d[l].first,l++,r--;
			else if (d[l].first<d[r].first)
			{
				int cha=d[r].first-d[l].first;
				sum+=d[l].first;
				int pos=l;
				l++;
				while (cha)
				{
					if (l>=r)
					{
						printf("%lld",sum);
						return 0;
					}
					int a=d[l].first;
					d[l].first=(d[l].first>=cha?d[l].first-cha:0);
					sum+=a-d[l].first;
					if (d[l].first==0)
					{
						d[pos].first+=a;
						d.erase(d.begin()+l);
					}
					else
						d[pos].first=d[r].first;
					cha=(a>=cha?0:cha-a);
					if (cha==0)
						break;
					l++;
				}
				r--;
			}
			else
			{
				int cha=d[l].first-d[r].first;
				sum+=d[r].first;
				int pos=r;
				r--;
				while (cha)
				{
					if (l>=r)
					{
						printf("%lld",sum);
						return 0;
					}
					int a=d[r].first;
					d[r].first=(d[r].first>=cha?d[r].first-cha:0);
					sum+=a-d[r].first;
					if (d[r].first==0)
						d[pos].first+=a;
					else
						d[pos].first=d[l].first;
					cha=(a>=cha?0:cha-a);
					if (cha==0)
						break;
					r--;
				}
				l++;
			}
		}
	}
	printf("%lld",sum);
	return 0;
}
