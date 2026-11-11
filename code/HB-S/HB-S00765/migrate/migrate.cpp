#include<bits/stdc++.h>
using namespace std;
int c,t;
bool fun(int a[2000006],int n){
        int d=a[2]-a[1];
        for(int i=1;i<n;i++){
            if(a[i+1]-a[i]!=d) return 0;
        }
        return 1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
cin>>c>>t;
while(t--){
    int n,d,a[2000006]={},ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int k=abs(a[1]-a[n]);
    if(k<=d){
            if(n>4){
                cout<<0<<endl;
                continue;
            }
        if(n<4){
            cout<<0<<endl;
        }
    }
    if(fun(a,n)){
        cout<<2<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(abs(a[i]-a[j])<=d&&abs(a[1]-a[i])<=d&&abs(a[i]-a[n])<=d){
                    ans++;
                }
            }
    }
        cout<<ans<<endl;
}
return 0;
}
