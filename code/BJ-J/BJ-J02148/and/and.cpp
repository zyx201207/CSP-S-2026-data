#include<bits/stdc++.h>
int a[200005];
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1)
    {
        cout<<a[1];
        return 0;
    }
    return 0;
}
