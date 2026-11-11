#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],aa[500005],f[300005],ans[300005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        aa[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(f[a[j]]!=0){
                for(int k=f[a[j]];k<j;k++){
                    f[a[k]]=0;
                    a[k]=0;
                }
            }
            f[a[j]]=j;
        }
        for(int j=i;j<=n;j++){
            if(a[j]!=0){
                ans[a[j]]++;
            }
            else a[j]=aa[j];
        }
        fill(f,f+m+1,0);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
