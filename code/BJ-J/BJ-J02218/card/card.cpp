#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300005],bf[500005],zp[500005];
void find(int x){
    int sz[300005];
    for(int i=1;i<=m;i++){
        sz[i]=0;
    }
    for(int i=x;i<=n;i++){
        bf[i]=zp[i];
        if(sz[bf[i]]==0){
            sz[bf[i]]=i;
        }
        else{
            for(int j=sz[bf[i]];j<i;j++){
                sz[bf[j]]=0;bf[j]=0;
            }
            sz[bf[i]]=i;
        }
    }
    for(int i=x;i<=n;i++){
        ans[bf[i]]++;

    }
    return;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>zp[i];
    }
    for(int i=1;i<=n;i++){
        find(i);
    }
    cout<<ans[1];
    for(int i=2;i<=m;i++){
        cout<<" "<<ans[i];
    }
    return 0;
}
