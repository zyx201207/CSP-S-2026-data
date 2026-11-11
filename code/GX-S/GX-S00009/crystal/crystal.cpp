#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=500005;
int n;
ll m,a[N],s[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i,now=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if((i-mid)*a[i]-s[i-1]+s[mid-1]<=m) now=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,(ll)i-now+1);
    }
    cout<<ans;
	return 0;
}
