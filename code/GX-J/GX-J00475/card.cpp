#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card1.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[5000000],b[5000000],ans[5000000],c[5000000],s;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(c[i]==1){
            s++;
        }
    }
    for(int j=1;j<=n;j++){
        for(int x=j;x<=n;x++){
            if(a[j]==a[x]){
                for(int i=j;i<x;i++){
                    b[i]=0;
                }
            }
        }
        for(int i=j;i<=n;i++){
            if(b[i]!=0){
                ans[b[i]]++;
            }
        }
    }
    for(int i=1;i<=s;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
