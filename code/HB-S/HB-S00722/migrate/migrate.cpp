#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int b[10000000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,d;
    cin>>n>>d;
    int x,y;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long s=0;
    for(int i=1;i<n;i++){
        if(a[i+d]<a[i-1]){
            s++;
           }

    }
    long long ans=0;
    cin>>x>>y;
    for(int i=0;i<x;i++){
        cin>>b[i];

    }
    for(int i=1;i<x;i++){
        if(b[i+y]<b[i-1]){
            ans++;
        }
    }
    cout<<s-1<<endl<<ans<<endl;


    return 0;
}
