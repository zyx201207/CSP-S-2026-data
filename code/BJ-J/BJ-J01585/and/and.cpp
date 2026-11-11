#include<bits/stdc++.h>
using namespace std;
int a[200000+7];
int n,m;
int mxawy=0;
void f(int z,int x,int c)
{
    if(z==1)
    {
        for(int i=x;i<=n;i++)
        {
            mxawy=max(mxawy,c&a[i]);
        }
        return ;
    }
    if(x==n) return ;
    for(int i=x;i<=n;i++)
    {
         f(z-1,i+1,c&a[i]);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    f(m,1,pow(2,30)-1);
    cout<<mxawy;
    return 0;

}
