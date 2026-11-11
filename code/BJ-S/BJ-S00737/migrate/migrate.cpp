#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        int n,m,a[200005]={};
        cin>>n>>m;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        int ans=n-2*m;
        if(ans>0){
            cout<<ans+1<<endl;
        }else{
            cout<<"0";
        }
    }
    return 0;
}