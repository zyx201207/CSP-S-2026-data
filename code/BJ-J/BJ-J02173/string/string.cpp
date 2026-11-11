#include<bits/stdc++.h>
#define ll long long
const int N=2e5+10;
//const int M=2e7+5;
int a[N];
char c[N];
//char s[M];
unsigned ll ans;
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        mx=max(mx,a[i]);
    }
    int i=1,j=n;
    while(i<j)
    {
        if(a[i]==a[j])
        {
            if(c[i]==c[j])
            {
                i++;
                j--;
            }
            else
            {
                i++;
                j--;
                ans+=a[i];
            }
        }
        else
        {
            if(c[i]==c[j])
            {
                //ans+=min(a[i],a[j]);
                if(a[i]>a[j])
                {
                    a[i]-=a[j];
                    j--;
                }
                else
                {
                    a[j]-=a[i];
                    i++;
                }
            }
            else
            {
                ans+=min(a[i],a[j]);
                if(a[i]>a[j])
                {
                    a[i]-=a[j];
                    j--;
                }
                else
                {
                    a[j]-=a[i];
                    i++;
                }
            }
        }
    }
    cout<<ans;
    /*else
    {
        ll cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=a[i];j++)
            {
                s[j+cnt]=c[i];
            }
            cnt+=a[i];
        }
        unsigned ll tot=0;
        for(int i=1;i<=cnt/2;i++)
        {
            if(s[i]==s[cnt-i+1])
            {
                continue;
            }
            else
            {
                tot++;
            }
        }
        cout<<min(tot,ans);
    }*/
    return 0;
}
