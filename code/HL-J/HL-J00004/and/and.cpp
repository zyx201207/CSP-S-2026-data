#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    int maxn=-100;
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {

            for(int j=i+1;j<=n;j++)
            {

                if(a[i]&a[j]>maxn)
                {
                    maxn=a[i]&a[j];
                }

            }
        }

    }
    if(m==1)
    {


        if(a[i}>maxn)
        {
            maxn=a[i];
        }


    }
    cout<<maxn;
    return 0;
}


