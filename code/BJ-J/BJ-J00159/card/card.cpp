#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[300005],t;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        for(int i=n;i>=k;i--){
            for(int j=k;j<i;j++){
                if(a[j]==a[i]){
                    sum[a[i]]++;
                    i=j;
                    t=1;
                }
            }
            if(!t){
                sum[a[i]]++;
            }
            t=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
