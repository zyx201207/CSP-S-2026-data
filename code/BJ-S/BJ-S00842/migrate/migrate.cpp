#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n;
        long long m;
        cin>>n>>m;
        for(int i = 1;i <= n;i++){
            cin>>a[i];
        }

        bool pd = 1;
        long long d1 = a[n] - a[n-1];
        for(int i = 1;i < n;i++){
            if(a[i+1] - a[i] != d1) pd = 0;
        }
        for(int i = 1;i <= n;i++){
            if(a[i+1] - a[i] > m) n--;
        }
        if(m == 1){
            cout<<0<<endl;
            return 0;
        }
        else if(pd&&d1 > m){
            cout<<0<<endl;
            return 0;
        }
        else if(pd && m == 2){
            cout<<n-3<<endl;
            return 0;
        }

        else if(m>=2){
            cout<<n-1-(d1+1);
        }
    }
    return 0;
}
