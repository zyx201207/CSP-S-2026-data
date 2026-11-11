#include<bits/stdc++.h>
using namespace std;
int n,k,imax=INT_MIN;
long long sum=0,step;
struct pos
{
	long long gs;
	char zm;
}a[200005];
bool pd;
map<long long,long long>m;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].gs>>a[i].zm;
		step+=a[i].gs;
		m[a[i].zm]+=a[i].gs;
		if(imax<m[a[i].zm])
		{
			imax=m[a[i].gs];
			k=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].zm!=a[n-i+1].zm)
		sum+=a[i].gs;
	}
	cout<<sum;
	return 0;
}
