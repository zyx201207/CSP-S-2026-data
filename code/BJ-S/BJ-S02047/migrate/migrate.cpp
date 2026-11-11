#include<bits/stdc++.h>
using namespace std;
int c,n;
int t,m;
int a[100005];
int f[100005];
int main(){
    freopen("migrate.in"."r",stdin);
    freopen("migrate.out"."w",stdout);
    cin>>c>>n;
    for(int p=1;p<=n;p++){
        cin>>t>>m;
        for(int i=1;i<=t;i++){
            cin>>a[i];
        }
        int d=a[2]-a[1];
        if(m==d){
            cout<<0;
            return 0;
        }
        cout<<t-2*(m/d)+1;
    }
}