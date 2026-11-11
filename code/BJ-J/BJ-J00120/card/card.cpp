#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int now[500005];
int ans[100005];
int pos=0;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            now[j]=0;
        pos=0;
        for(int j=i;j<=n;j++)
        {
            bool flag=0;
            int k=1;
            for(;k<pos;k++)
            {
                if(now[k]==a[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                for(int l=pos;l>=k;l--)
                {
                    now[l]=0;
                    pos--;
                }
            }
            now[++pos]=a[j];
        }
        for(int i=1;i<=pos;i++)
        {
            ans[now[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}