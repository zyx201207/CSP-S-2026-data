#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        int x=-1;
        for(int i=1;i<=n;i++){
            if(x<a[i]) x=a[i];
        }
        cout<<x;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
}
