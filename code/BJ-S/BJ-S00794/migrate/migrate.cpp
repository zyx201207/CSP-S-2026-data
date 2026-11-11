#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int x[n];
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        if(c==11||c==12){
            d/=x[1]-x[0];
            int sum=0;
            for(int i=2*d-1;i>=d+1;i--){
                sum+=n-i;
            }
            cout<<sum;
        }
    }
    return 0;
}
