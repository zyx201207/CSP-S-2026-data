#include<bits/stdc++.h>
using namespace std;
struct node{
    int num,pre;
}arr[300010];
long long fa[300010],ans[300010],cnt[300010],t[300010];
long long n,m;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].num;
        arr[i].pre=fa[arr[i].num];
        fa[arr[i].num]=i;
        cnt[arr[i].num]++;
    }

    for(int i=1;i<=n;i++)
    {
        cnt[arr[i-1].num]--;
        for(int j=1;j<=m;j++)
        {
            t[j]=cnt[j];
        }
        for(int j=i;j<=n;j++)
        {
            if(arr[j].pre==i)
            {
                int l=arr[j].pre,r=j-1;
                for(int k=l;k<=r;k++)
                {
                    int x=arr[k].num;
                    if(t[x]==1)t[x]--;
                }
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(t[j]!=0)ans[j]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
