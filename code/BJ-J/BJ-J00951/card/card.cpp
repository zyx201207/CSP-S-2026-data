#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,c=1,a[100005]={0},d[100005]={0},b[300005]={0};
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=n;j++)
        {
            for(long long k=1;k<c;k++)
            {
                if(d[k]==a[j])
                {
                    for(long long z=k;z<=c;z++)
                    {
                        d[z]=0;
                    }
                    c=k;
                    break;
                }
            }
            d[c]=a[j];
        }
        for(long long j=1;j<=c;j++)
        {
            b[d[j]]++;
            d[j]=0;
        }
        c=1;
    }
    for(long long i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
