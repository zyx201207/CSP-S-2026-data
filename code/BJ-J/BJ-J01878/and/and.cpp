#include<bits/stdc++.h>
using namespace std;
int a[200006];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for (int i=30;i>=0;i--){
        int v=(1<<i);
        int cnt=0;
        for (int j=1;j<=n;j++){
            if (a[j]&v) cnt++;
        }
        if (cnt>=m){
            for (int j=1;j<=n;j++){
                if (!(a[j]&v)) a[j]=0;
            }
            ans+=v;
        }
    }
    cout<<ans;
}
