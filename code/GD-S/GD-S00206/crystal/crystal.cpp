#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],v[999999],maxv=-1;
int main(){
    freopen("crystal.in","r",stdin);
   	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++) v[a[i]]++;
	for(long long i=1;i<=a[n];i++) maxv=max(maxv,v[i]);
	while(m>0)
	{
		for(long long i=1,j=1;i<=n,j<=n;)
		{
			if(a[j]==a[i]) j++;
			else
			{
				long long p=j-i+1;
				if(m>p) m-=p;
				else if(m<p)
				{
					if(v[a[j]+1]+m>maxv)
					{
						v[a[j]+1]+=m;
						maxv=v[a[j]+1];
					}
					else
					{
						i=j;
						j=i+1;
					} 
				}
				else
				{
					m-=p;
					break;
				}
			}
		}
	}
	for(long long i=1;i<=a[n];i++) maxv=max(maxv,v[i]);
	cout<<maxv;
	return 0;
}
