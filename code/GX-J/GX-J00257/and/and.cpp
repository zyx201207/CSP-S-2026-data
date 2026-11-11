#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],len=0,tmp=0,mx,b[200010],cnt;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        tmp=max(tmp,a[i]);
    }
    while(tmp)
    {
        len++;
        tmp>>=1;
    }
    len--;
    while(len>=0)
    {
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]&(1<<len))b[++cnt]=a[i];
        }
        if(cnt>=m)
        {
            mx+=1<<len;
            n=cnt;
            for(int i=1;i<=n;i++)a[i]=b[i];
        }
        len--;
    }
    cout<<mx;
    return 0;
}
