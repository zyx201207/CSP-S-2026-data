#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    int m;
    int r=1;
    cin>>n>>m;
    int Q=0;
    int L=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int o=0;o<m;o++)
    {
        if(a[Q]<=a[Q+r])
        {
            if(a[Q]!=a[Q+r])
            {
                a[Q]=a[Q]+1;
            }
            if(a[Q]==a[Q+r])
            {
                L++;
                Q++;
            }
        }
        if(a[Q]>>a[Q+r])
        {
            while(a[Q]>>a[Q+r])
            {
                if(a[Q]<=a[Q+r]||r==n-Q-1)
                {
                    break;
                }
                else{r++;}
            }
            if(r==n-Q-1)
            {
                L=L;
            }
            if(r<<n-Q-1)
            {
                if(a[Q]!=a[Q+r])
                {
                    a[Q]=a[Q]+1;
                }
                if(a[Q]==a[Q+r])
                {
                    L++;
                    Q=Q+r;
                    r=1;
                }
            }

        }

    }
    cout<<L;
    return 0;
}
