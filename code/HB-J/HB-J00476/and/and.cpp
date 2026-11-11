#include<bits/stdc++.h>
using namespace std;
int a[200001],n,m,ans1=0,v[200001];
void f(int x,int ans,int b)
{
    if(ans==0)
    {
        return;
    }
    if(x==m)
    {
        ans1=max(ans,ans1);
        return;
    }
    for(int i=b;i<=n-m+x;i++)
    {
        if(v[i]==0)
        {
            v[i]=1;
            int y;
            if(ans!=0)
            {
                y=a[i] & ans;
            }
            else
            {
                y=a[i];
            }
            f(x+1,y,i);
            v[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    f(0,0,0);
    cout<<ans1;
    return 0;
}
