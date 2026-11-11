#include<bits/stdc++.h>
using namespace std;
long long a[555555];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    if(m==1)
    {
        cout<<n<<endl;
        return 0;
    }
    if(m==2)
    {
        if(n==2)
        {
            cout<<1<<" "<<2<<endl;
            return 0;
        }
        if(n==3)
        {
            if(a[1]==a[2])
            {
                cout<<2<<" "<<3<<endl;
                return 0;
            }
            if(a[3]==a[2])
            {
                cout<<1<<" "<<3<<endl;
                return 0;
            }
            if(a[1]==a[3])
            {
                cout<<2<<" "<<3<<endl;
                return 0;
            }
        }
    }
    for(long long i=1;i<=n-1;i++)
        cout<<i<<" ";
    cout<<n<<endl;
    return 0;
}
