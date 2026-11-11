#include<bits/stdc++.h>
using namespace std;

long long n,m,sum,d,ans;
long long a[500009];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << noboolalpha;
    cin>>n>>m;
    int dt=2147483647;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        sum+=a[i-1];
        cout<<sum+m<<" "<<a[i]*2<<endl;
        if(sum+m<=a[i]*2)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]!=a[j])break;
                d++;
            }
            if(dt>=a[i]*2-sum-m)
            {
                ans=i+1+d;
                d=0;
                dt=a[i]*2-sum-m;
            }
        }
    }
    if(ans)
    {
        cout<<ans;
    }
    else
    {
        cout<<n;
    }
    return 0;
}
