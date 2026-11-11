#include <bits/stdc++.h>
using namespace std;

const long long NN=5e5+5;
long long n,m;
long long a[NN]{};
long long ui=1,uj=1;
long long maxa=0,sumn=0,w=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out", "w",stdout);

    cin>>n>>m;
    for (long long i = 1; i <= n; i++)
        cin>>a[i];

    sort(a+1,a+n+1);
    for (; uj <= n; uj++)
    {
        sumn+=a[uj];
        w=a[uj]*(uj-ui+1)-sumn;
        if(w>m)
        {
            sumn-=a[ui++];
            continue;
        }
        else
        {
            if(maxa<uj-ui+1)
                maxa=uj-ui+1;
        }
    }

    cout<<maxa<<endl;

    return 0;
}

// ac 14:51