#include<bits/stdc++.h>
using namespace std;
int a[500005],now1[5000005],now_table[5000005],ans[5000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int t=1;t<=n;t++)
    {
        int p=0,cnt=0;
        for(int i=t;i<=n;i++) now1[++p]=a[i];
        for(int i=1;i<=p;i++)
        {
            if(now_table[now1[i]]==0) now_table[++cnt]=now1[i];
            else{
                int pos=1;
                for(int j=1;j<=cnt&&now_table[j]!=now1[i];j++) pos++;
                cnt=pos;
                now_table[pos]=now1[i];
            }
        }
        for(int i=0;i<=cnt;i++)
        {
            ans[now_table[i]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
