#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];;
int ans[300005];
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i;j--){
            for(int k=j+1;k<=n;k++){
                if(a[k]==a[j]){
                    ans[a[j]]-=1;
                }
            }
            ans[a[j]]+=1;
        }
    }
    ans[a[n]]=n;
    for(int i=0;i<m-1;i++){
        cout<<ans[i]<<" ";
    }
    cout<<ans[m];
    return 0;
}
