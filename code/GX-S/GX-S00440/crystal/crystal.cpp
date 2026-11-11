#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[50001];
int f(int d,int x,int y)
{
    if(a[y]-a[x]<0||d<a[y]-a[x]||x>n)
        return 0;
    return max(f(d-a[y]+a[x],x+1,y)+1,f(d,x+1,y));

}
int main()
{
    freopen("crystalin","r",stdin);
    freopen("crystalout","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]>a[j])
                swap(a[i],a[j]);
        }
    }
    int s=0;
    for(int i=1;i<=n;i++)
    {
        s=max(s,f(m,1,i));
    }
    cout<<s;
    return 0;
}


