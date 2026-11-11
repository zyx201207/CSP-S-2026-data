#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[300005],ans[300005],p=1;
int main()
{
    freopen("card.in", "r",stdin);
    freopen("card.out", "w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(c[a[j]]==0){
                b[j]=a[j];
                c[a[j]]=1;
            }
        }
        for(int i=1;i<=m;i++){
            if(c[i]==1){
                ans[i]++;
            }
        }
        for(int i=1;i<=m;i++){
            c[i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0; 
}
