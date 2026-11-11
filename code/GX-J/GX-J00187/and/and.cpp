#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[7891],s=0,c=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        for(int i=0;i<n;i++)
        {
            s=a[i]&a[i+1];
            c=max(s)
        }
    cout <<c;
    return 0;
}
