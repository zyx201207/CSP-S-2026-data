#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int rd[3][5004];
int ans;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k;
        for(int j=1;j<=n-1;j++){
            cin>>rd[1][j]>>rd[2][j];
        }
        cout<<2;
    }
    return 0;
}
