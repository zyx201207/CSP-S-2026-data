#include<bits/stdc++.h>
using namespace std;
char b[200010];
long long a[200010];
long long aa[200010];
char bb[200010];
int main()
{
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    long long n,cnt=0;
    int u=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>b[i];
        long long h=cnt;
        cnt+=a[i];
        for(int j=h;j<=cnt;j++)
        {
           bb[i]=b[i];
        }
    }

    for(int i=2;i<=n;i++)
    {
        if(b[i]!=b[i-1])
        {
            u=1;
            break;

        }

    }
    if(u==1)
    {
        cout<<0;
        return 0;

    }
    int y=cnt/2;
    if(cnt%2==1)
    {
        for(int i=1;i<=y;i++)
        {
            if(bb[i]!=bb[i+y+1])
            {
                cnt++;
            }
        }
    }
    else
    {
        for(int i=1;i<=y;i++)
        {
            if(bb[i]!=bb[i+y])
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
