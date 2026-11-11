#include<bits/stdc++.h>
using namespace std;
int a[500005],v[300005],p[300005],m,n;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(p,0,sizeof(p));
        for(int j=i;j<=n;j++)
        {
            if(p[a[j]]>0)
            {
                for(int i=p[a[j]];i<=j;i++)
                    p[a[i]]=0;
                p[a[j]]=j;
            }
            else
            {
                p[a[j]]=j;
            }
        }
        for(int i=1;i<=m;i++)
        {
            v[i]+=p[i]>0?1:0;
        }
    }
    for(int i=1;i<=m;i++)
        cout<<v[i]<<" ";
   return 0;
}
