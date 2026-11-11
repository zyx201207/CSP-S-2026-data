#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M=500005;
int a[M],cnt[M];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int k=1;k<=n;k++)
    {
        int b[M];
        int sum=0;
        for(int i=k;i<=n;i++)
        {
            bool flag=true;
            int weizhi=0;
            for(int j=1;j<=sum;j++)
            {
                if(b[j]==a[i])
                {
                    weizhi=j;
                    flag=false;
                    break;
                }
            }
            if(flag==true)
            {
                sum++;
                b[sum]=a[i];
            }
            else
            {
                for(int j=weizhi;j<=sum;j++)
                {
                    b[j]=0;
                }
                sum=weizhi-1;
                sum++;
                b[sum]=a[i];
            }
        }
        for(int i=1;i<=sum;i++)
        {
            cnt[b[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    cout<<"\n";
    return 0;
}