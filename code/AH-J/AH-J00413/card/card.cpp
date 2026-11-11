#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],t[300005],t1[300005],b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            for(int k=i;k<=n;k++){
                if(j!=k&&a[j]==a[k]){
                    for(int l=j;l<=k;l++){
                        a[l]==0;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(a[j]>=1){
                t[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}

