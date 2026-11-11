#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==m){
        for(int i=n;i>=1;i--){
            cout<<i<<" ";
        }
    }else{
        int ans[m+1]={};
        int j=1;
        int a[n+1]={};
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        while(1){
            int k=j;
            int a1[m+1]={};
            for(int i=k;i<=n;i++){
                if(a1[a[i]]==0){
                    a1[a[i]]=1;
                }else{
                    j=i+1;
                }
            }
            for(int i=j;i<=n;i++){
                ans[a[i]]++;
            }
            j+=1;
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}
