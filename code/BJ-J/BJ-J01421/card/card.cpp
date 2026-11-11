#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],tong[500005],b[500005],pos;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        pos=0;
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++){
            b[++pos]=a[j];
            for(int k=1;k<pos;k++){
                if(b[k]==a[j]){
                    pos=k;
                }

            }
        }
        for(long long j=1;j<=pos;j++)
            if(b[j]!=-1) tong[b[j]]++;
    }

    for(long long i=1;i<=m;i++)
        cout<<tong[i]<<" ";

    return 0;
}