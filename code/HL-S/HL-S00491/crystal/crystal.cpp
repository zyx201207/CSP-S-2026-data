#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100000010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
         cin>>a[i];
	}
	sort(a,a+n+1);
    for(int i=1;i<=n;i++)
    {
    m-=a[n%2]-a[n%2-i];
	}
	for(int i=1;i<=n;i++)
    {
    if(m&&a[n%2+i]+1==a[n%2+i+1])cnt+=1;
    }
    if(m)cout<<m+cnt+n/2;
    cout<<n/2;
	return 0;
}	