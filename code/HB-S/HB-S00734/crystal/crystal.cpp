#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],ans=-1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int j=0;j<n;j++)
    {
        ll sum=0,cnt=0,num=j;
        for(int i=a[j];1;cnt+=sum,i++)
        {

            if(a[num]==i)
            {
                for(;i==a[num];num++);
                sum+=(num-j);
            }
            if(cnt+sum>m) break;
        }
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
	return 0;
}
