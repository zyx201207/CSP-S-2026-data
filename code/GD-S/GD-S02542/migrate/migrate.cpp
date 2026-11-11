#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
ll c,t;
ll d,x[N],n;
ll in()
{
	ll w=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		w=w*10+c-'0';
		c=getchar();
	}
	return w*f;
}
struct stu
{
	int w;
};
vector<stu>q;
int main()
{
//	cout<<1000000000000000000-999997142608141581<<endl;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		n=in();d=in();
		for(ll i=1;i<=n;i++) x[i]=in();
		ll t=2*d/(x[2]-x[1])-1;
//		if(n==699940) 
//		cout<<endl<<(x[2]-x[1])<<endl<<endl;
		if(n-1<t||d<(x[2]-x[1])||t==1) printf("0\n");
		else printf("%lld\n",n-t);
	}
	return 0;
} 
