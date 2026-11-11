#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int ans[N];
int pos[N];
int num[N];
signed main()
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
        int t=0;
        for(int j=1;j<=m;j++)
        {
            pos[j]=-1;
        }
        for(int j=i;j<=n;j++)
        {
                if(pos[a[j]]!=-1)
                {
                    for(int k=pos[a[j]]+1;k<=t;k++)
                    {
                        pos[num[k]]=-1;
                    }
                    t=pos[a[j]]-1;
                    pos[a[j]]=t+1;
                    t++;
                    num[t]=a[j];

                }
                else
                {
                    t++;
                    num[t]=a[j];
                    pos[a[j]]=t;
                }


        }
        for(int j=1;j<=t;j++)
        {
            //cout<<num[j]<<" ";
            ans[num[j]]++;
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++)
    {

        cout<<ans[i]<<" ";
            }
    return 0;
}
