#include <bits/stdc++.h>
using namespace std;
const int N=1e6+20;
typedef long long ll;
ll f[N],a[N],p[N];
ll n,m,sum=0,num=1;
bool o,l;
int main()
{

		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==f[i+1])
			l=true;
	} 
	if(l)
		cout<<n;
	sort(f+1,f+n);
	for(int i=1;i<=n;i++)
	{
		a[i]=f[i+1]-f[i];
	}
	a[n]=0;
	o=true;
	for(int i=1;i<=n;i++)
	{
		p[i]=a[i]+a[i-1]*num;
		sum+=p[i];
		if(sum>m)
			break;
		num++;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;

}
