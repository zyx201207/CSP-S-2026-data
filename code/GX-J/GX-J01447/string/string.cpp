#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,i,l,r,x[100005],a,b,s,t;
char c[100005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>c[i];
    }
    l=0;
    r=n-1;
    a=x[0];
    b=x[n-1];
    s=0;
    while(l<r)
    {
        t=min(a,b);
        if(c[i]!=c[r])
        {
            s+=t;
        }
        a-=t,b-=t;
        if(a==0)
        {
            l++;
            a=x[l];
        }
        if(b==0)
        {
            r--;
            b=x[r];
        }
    }
    cout<<s<<endl;
    return 0;
}
