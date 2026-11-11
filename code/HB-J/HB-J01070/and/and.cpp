#include<bits/stdc++.h>
using namespace std;
int c[n];
int main()
{
    freopen("and.in","r",stdin);
     freopen("and.out,"w",stdout);
     int n,m;
     cin>>n>>m;
     for(int i=1;i<=n;i++)
     cin>>c[i];
     sort(c+1,c+n+1);
     int num=0;
     for(int i=1;i<=n;i++)
     {
        if(c[i]%2==1)
        num++;

        if(num==m)
        {
        cout<<c[i];
        }
     }
    return 0;
}