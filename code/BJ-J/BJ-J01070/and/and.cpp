#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in",",r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+5]={};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int MAX=-1;
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            MAX=max(a[i],MAX);
        }
        cout<<MAX;
        return 0;
    }
    for(int i=m;i<=n;i++)
    {
        int x=a[i];;
        for(int j=i-1;j>=i-m+1;j--)
        {
            x&=a[j];
        }
        MAX=max(x,MAX);
    }
    cout<<MAX;
}
