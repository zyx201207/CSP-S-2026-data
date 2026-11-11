#include<bits/stdc++.h>
using namespace std;
int a[200010],cnt=1,sum[200010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t=n;
    while(t--){
        int b[n],x=1;
        for(int i=1;i<=n;i++){
            b[i]=0;
        }
        for(int i=cnt;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i]==b[j]){
                    x=j;
                    for(int k=j;k<=n;k++){
                        b[k]=0;
                    }
                }
            }
            b[x]=a[i];
            x++;
        }
        for(int i=1;i<x;i++){
            sum[b[i]]++;
        }
        cnt++;
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }

    return 0;
}
