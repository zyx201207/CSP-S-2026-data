#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long maxx=0;
	for(int i=1;i<=n;i++)
    {
        long long k=m;
        long long cnt=1;
        for(int j=i-1;j>=1;j--)
        {
            if(k<(a[i]-a[j]))break;
            cnt++;
            k-=a[i]-a[j];
        }maxx=max(maxx,cnt);
    }cout<<maxx;
	return 0;
}
