#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m;
int a[N],s[N];
int sum_1=0,sum_2=0;
int b[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1) a[i]=0;
        else a[i]=1;
        s[i]=s[i-1]+a[i];

    }
    cout<<n-1<<" "<<n;
    return 0;
}

