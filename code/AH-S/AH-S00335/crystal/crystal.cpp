#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N];
__int128 b[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i];
	}
	long long ma=1;
	int l=1;
	__int128 ts=0,as=1;
	for(int i=2;i<=n;i++)
	{
		ts+=(b[i]-b[i-1])*as;
	    as++;
	    while(ts>m)
	    {
		    ts-=(b[i]-b[l]);
	    	as--;
		    l++;
		}
		ma=max(ma,(long long)as);
	}
	cout<<ma;
}
