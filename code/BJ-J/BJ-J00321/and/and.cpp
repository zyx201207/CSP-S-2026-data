#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;
int a[N];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);


    int n,m;
    cin>>n>>m;
    if(m==1){
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
return 0;
}
