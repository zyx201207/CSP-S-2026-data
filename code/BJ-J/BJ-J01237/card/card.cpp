#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],an[500005],ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[n+1];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j]){
                an[a[i]]=1;
                i=j;
                break;
            }
            if(j==n) an[a[i]]=1;
        }
        for(int j=1;j<=m;j++) ans[j]+=an[j];
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
