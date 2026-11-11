#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[300005],d[300005];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++) {
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        int l=1;
        for(int j=i;j<=n;j++) {
            if(c[a[j]]==0) {
                b[l]=a[j];
                c[a[j]]=l++;
                continue;
            }
            for(int k=c[a[j]]+1;k<=l-1;k++) {
                c[b[k]]=0;
                b[k]=0;
            }
            l=c[a[j]]+1;
        }
        for(int j=1;j<l;j++)
            d[b[j]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<d[i]<<' ';
    return 0;
}