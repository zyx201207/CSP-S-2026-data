#include <bits/stdc++.h>
using namespace std;
int n,energy[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>energy[i];
    }
    long long cha=energy[2]-energy[1];
    int ans=0;
    while(m>=0)
    {
        m=m-cha;
        cha+=cha;
        if(m>=0)
        {
            ans++;
        }
    }
    cout<<ans+1;
    return 0;
}
