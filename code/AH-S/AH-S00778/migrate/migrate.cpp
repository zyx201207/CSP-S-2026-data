#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        long long s[n];
        for(long long i=0;i<n;i++){
            cin>>s[i];
        }
        if (n<=3||d==1) cout<<"0";
        else if(s[3]-s[0]<=d) cout<<"0";
        else cout<<n-3;
    }
    return 0;
}
