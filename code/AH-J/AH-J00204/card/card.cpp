#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r", stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+10];
    for(int i = 0;i<n;i++){
        cout<<a[i];
    }
    int ans = 0;
    for(int j = 0;j<n;j++){
        if(a[j]==m){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
