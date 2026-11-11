#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],s;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(m>0)
    {
        m--;
        sort(a+1,a+n+1);
        a[1]++;
        int e=a[1],r[20],d=1;
        for(int i=1;i<20;i++)
        {
            r[i]=0;
        }
        for(int i=1;i<n;i++)
        {
            if(e==a[i])
            {
                r[d]++;
            }
            else
            {
                d++;
            }
        }
        sort(r+1,r+d+1);
        s=max(s,r[d]);
    }
    cout<<s;
    return 0;
}
