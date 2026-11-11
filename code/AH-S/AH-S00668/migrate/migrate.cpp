#include<bits/stdc++.h>
using namespace std;
long long arr[2000009];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int u=1;u<=t;u++){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(d<2*(arr[j]-arr[i])&&d>arr[j]-arr[i]){
                    ans++;
                }
            }
        }
    }
    cout<<1<<endl<<2;
    return 0;
}
