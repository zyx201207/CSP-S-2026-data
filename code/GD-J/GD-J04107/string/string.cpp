#include<iostream>
using namespace std;
#define ll unsigned long long 

ll n,s;
struct aph
{
	ll cnt;
	char c;
}a[200005];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out","w", stdout);
	cin >>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].cnt>>a[i].c;
		s+=a[i].cnt;
	}
	ll res=0;
	ll pid=1, psum=a[pid].cnt, tid=n, tsum=a[tid].cnt;
	for(ll i=1;i<=(s>>1);i++)
	{
		// cout<<pid<<' '<<tid<<' ';
		if(i>psum)
		{
			pid++;
			psum+=a[pid].cnt;
		}	
		if(i>tsum)
		{
			//cout<<s-i+1<<endl;
			tid--;
			tsum+=a[tid].cnt;
		}
		//cout<<pid<<' '<<tid<<"\n\n";
		if(a[tid].c!=a[pid].c)
		{
			//cout<<a[tid].c<<' '<<a[pid].c<<endl;
			res++;
		}
	}
	cout<<res;
	return 0;
}
