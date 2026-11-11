#include<bits/stdc++.h>
using namespace std;
int a[500010];
int tmp[500010];
int cnt[300010];
int ed;
int n,m;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>tmp[i];
    for(int k=0;k<n;k++)
    {
        ed=-1;
        for(int x=k;x<n;x++)
        {
            for(int i=0;i<=ed;i++)
            {
                if(a[i]==tmp[x])
                {
                    ed=i-1;
                    break;
                }
            }
            a[++ed]=tmp[x];
        }
        for(int i=0;i<=ed;i++)
        {
            cnt[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
