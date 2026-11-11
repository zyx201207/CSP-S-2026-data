#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0,mx=0;
    int a[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i&j>=0){
                mx=max(mx,i&j);
            }
        }
    }
    cout<<ans;
    fclose("and.in","r",stdin);
    fclose("and.out","w",stdout);
}
