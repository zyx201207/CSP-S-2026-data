#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long pla[5004];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>pla[j];
        }
        for(int j=1;j<=n-1;j++){
            for(int k=j+1;k<=n;k++){
                ans++;
            }
        }
        cout<<ans/2<<endl;
    }
    return 0;
}
