#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
long long m=0;
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>b[i];
    }
    char c,d;
    long long e,f,ans=0;
    e=a[1];
    f=a[n];
    for(long long i=1,j=n;i<j;)
    {
        c=b[i];
        d=b[j];
        if(e==f)
        {
            if(c==d)
            {
                i+=1;
                j-=1;
                e=a[i];
                f=a[j];
            }
            else
            {
                i+=1;
                j-=1;
                ans+=e;
                e=a[i];
                f=a[j];
            }
        }
        else if(e<f)
        {
            if(c==d)
            {
                i+=1;
                f-=e;
                e=a[i];
            }
            else
            {
                i+=1;
                f-=e;
                ans+=e;
                e=a[i];
            }
        }
        else if(f<e)
        {
            if(c==d)
            {
                j-=1;
                e-=f;
                f=a[j];
            }
            else
            {
                j-=1;
                e-=f;
                ans+=f;
                f=a[j];
            }
        }
    }
    cout<<ans;
    return 0;
}