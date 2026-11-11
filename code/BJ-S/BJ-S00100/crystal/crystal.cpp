#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans=1;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int j=1,i=1;
    long long cost=0;
    while(i<=n)
    {
        i++;
        if(i>n)
            break;
        long long newcost=(i-j)*(a[i]-a[i-1])+cost;
        while(j<i&&newcost>m)
        {
            newcost-=(a[i]-a[j]);
            j++;
        }
        ans=max(ans,(long long)(i-j+1));
        cost=newcost;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}