#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d,ans=0,a[999];
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>a[i];
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=d;k++){
                if(a[i]+k==a[i]+k-1||a[i]+k==a[i]+k-2||a[i]+k==a[i]+k-3||a[i]+k==a[i]+k+1||a[i]+k==a[i]+k+2||a[i]+k==a[i]+k+3){
                    ans++;
                }
            }
        }
        cout<<i<<endl;
    }
    return 0;
    //rp++!!!
}
