#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,s=1,s1=0,x=0;
    int a[100001];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n;i>=1;i--)
    {
        for(int j=i-1;j>=1;j--)
        {
            x+=a[i]-a[j];
            s++;
            if(x>m)
            {
                break;
            }
        }
        if(s1<s)
        {
            s1=s;
        }
        s=0;
        x=0;
    }
    cout<<s1;
    return 0;
}
