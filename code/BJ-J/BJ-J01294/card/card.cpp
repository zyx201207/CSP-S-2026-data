#include<iostream>
using namespace std;
int n,m;
int a[50005];
int b[30005];
int flag1[50005],flag2[50005];
int ans[50005];
void find(int x,int y)
{
    if(x==0)
    {
        return;
    }
    ans[a[n-flag2[x]+1]]+=y;
    find(flag2[x],y);
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int cnt_cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(flag1[i]>0)
        {
            continue;
        }
        ans[a[n-i+1]]++;
        flag2[i]=flag2[i-1];
        if(flag1[i-1]==0)
        {
            flag2[i]=i-1;
        }
        int cnt=0;
        for(int j=1;j<n-i+1;j++)
        {
            if(a[j]==a[n-i+1])
            {
                flag1[n-j+1]=i;
                flag2[n-j+1]=i;
                cnt++;
                cnt_cnt++;
            }
        }
        ans[a[n-i+1]]+=cnt;
        find(i,cnt+1);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}