#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
long long ans;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++)
            s+=c[i];
    }
    ans=s.size()/2;
    int x=0;
    if(s.size()%2==0)//obuu
    {
        for(int i=0;i<ans;i++)
        {
            if(c[i]==c[n-i-1])
            {//jt dv vi pj dr
                if(a[i]>a[n-i])
                    ans=ans-(a[i]-a[n-i]);
                else
                    ans=ans-(a[n-i]-a[i]);
            }
        }
    }
    else//jiuu
    {
        for(int i=0;i<ans;i++)
        {
            if(c[i]==c[n-i-1])
            {//jt dv vi pj dr
                if(a[i]>a[n-i])
                    ans=ans-(a[i]-a[n-i]);
                else
                    ans=ans-(a[n-i]-a[i]);
            }
        }
    }
    cout<<ans;
    return 0;
}
