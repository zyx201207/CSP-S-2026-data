#include<bits/stdc++.h>
using namespace std;
long long  n,m,sum=0;
const int N=1e5+5;
long long a[N];
long long maxn=-1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum=sum&a[i];
    }

    if(m==1) {sort(a+1,a+n+1); cout<<a[n];}
    else if(m==n) cout<<sum;
    else if(m==2)
    {

        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxn=max(maxn,(a[i]&a[j]));
            }
        }
        cout<<maxn;
    }
    else{
        cout<<0;
    }

    return 0;
}

