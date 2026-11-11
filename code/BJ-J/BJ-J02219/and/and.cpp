#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long sum,maxx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==1)
            sum=a[i];
        sum=(sum&a[i]);
        maxx=max(maxx,a[i]);
    }
    if(m==1)
        cout<<maxx;
    if(m==n)
        cout<<sum;
    return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
