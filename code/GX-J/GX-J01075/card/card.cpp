#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],x[300001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
            int b[500001],c[300001],k=0;
            memset(b,0,sizeof(b));
            memset(c,0,sizeof(c));
            for(int j=i;j<=n;j++){
                k++;
                b[k]=a[j];
                c[b[k]]++;
            }
            for(int j=k;j>=i;j--){
                if(c[b[j]]>=2){
                    x[b[j]]++;
                    break;
                }
                else if(c[b[j]]==1){
                    x[b[j]]++;
                }
            }
    }
    for(int i=1;i<=m;i++)
        cout<<x[i]<<" ";
    return 0;
}
