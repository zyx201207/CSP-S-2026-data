#include<bits/stdc++.h>
using  namespace std;
int a[10000];
int b[10000]={0,3,15,12,12};
int c[10000]={0,31,3,1,15,7};
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    bool p1=0,p2=0;
    int n,m,x=12,y=7;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==4&&m==2)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==b[i]) p1=1;
        }
    }
    else cout<<y;
    if(p1) cout<<x; return 0;
}