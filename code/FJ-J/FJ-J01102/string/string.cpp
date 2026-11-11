#include<bits/stdc++.h>
using namespace std;
struct cha
{
	long long a;
	char c;
};
long long n,k,sum,a[200020],sum2,ans;
char c[200020];
vector<cha>l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	for(int i=1;;i++)
	{
		k=i;
		if(sum2+a[i]>sum/2)
			break;
		sum2+=a[i];
		l.push_back({a[i],c[i]});
	}
	if(sum2<sum/2)
	{
		l.push_back({sum/2-sum2,c[k]});
		r.push_back({a[k]-(sum/2-sum2),c[k]});
		k++;
	}
	else
		if(sum%2)
		{
			if(a[k]==1)
				k++;
			else
				a[k]--;
		}
	for(int i=k;i<=n;i++)
		r.push_back({a[i],c[i]});
	int ll=0,rr=r.size()-1;
	while(ll<l.size() and rr>=0)
	{
		if(l[ll].a>r[rr].a)
		{
			if(l[ll].c!=r[rr].c)
				ans+=r[rr].a;
			l[ll].a-=r[rr].a;
			rr--;
		}
		else 
			if(l[ll].a<r[rr].a)
			{
				if(l[ll].c!=r[rr].c)
					ans+=l[ll].a;
				r[rr].a-=l[ll].a;
				ll++;
			}
			else
			{
				if(l[ll].c!=r[rr].c)
					ans+=r[rr].a;
				ll++;
				rr--;
			}
	}
	cout<<ans;
	return 0;
}
