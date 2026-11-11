#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=200000+10;
int a[maxn];
int n,m,ans;
int main(){
freopen("add.in","r",stdin);
freopen("add.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int h=0;
        for(int i=1;i<=n;i++){
            h=max(h,a[i]);
        }
        cout<<h;
        return 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            ans=max(ans,ans^a[j]);

        }
    }

    cout<<ans;
    return 0;
}
