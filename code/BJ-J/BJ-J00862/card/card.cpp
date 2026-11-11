#include<bits/stdc++.h>
using namespace std;
bool flag[300010];
int last[500010];
int tmp[300010];
int a[500010];
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
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) flag[j]=false;
        for(int j=i;j<=n;j++)
        {
            if(!flag[a[j]])
            {
                flag[a[j]]=true;
                last[a[j]]=j;
            }
            else
            {
                for(int k=last[a[j]];k<j;k++)
                {
                    flag[a[k]]=false;
                }
                flag[a[j]]=true;
                last[a[j]]=j;
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(flag[j]==true)
            {
                tmp[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<tmp[i]<<" ";
    }
    return 0;
}