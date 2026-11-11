#include<bits/stdc++.h>
using namespace std;
long long a[555555];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    long long d=a[2]-a[1];
    long long k=m/d;
    long long s;
    for(long long i=1;i<=n;i++)
    {
        s++;
        k-=i;
        if(k<0)
        {
            k+=i;
            s--;
            break;
        }
    }
    cout<<s<<endl;
    return 0;
}
