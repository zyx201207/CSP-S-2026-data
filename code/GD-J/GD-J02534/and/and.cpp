#include <bits/stdc++.h>
using namespace std;
int cnt[40],cntt=0,n,m;
int ns[200005];
bool cmp(int a,int b)
{
    return a>b;
    return 0;
}
void hhhh(int hh)
{
    int cs=0;
    while(hh>0)
    {
        if(hh%2==1)
        {
            cnt[32-cs]++;
        }
        hh/2;
        cs++;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>ns[i];
    }
    sort(ns+1,ns+n+1,cmp);
    for(int i=1;i<=m;i++)
    {
        hhhh(ns[i]);
    }
    for(int i=32;i>0;i--)
    {
        int q=1;
        cntt+=q*(cnt[i]==m);
        q*=2;
    }
    cout<<cntt;
    return 0;
}
