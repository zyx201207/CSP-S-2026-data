#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d,island[2000006];
    cin>>c>>t;
    for(int i=0;i<t;i++){
            int ans=1;
        cin>>n>>d;
        for(int j=0;j<n;j++){
            cin>>island[i];
        }
        for(int j=1;j<n;j++){
            if((island[j]-island[j-1])<d){
                ans++;
            }
        }
        cout<<ans;
        ans-=ans/d;
        ans=ans-d;
        if(ans<0){
            cout<<1;
        }else{
            cout<<ans+1;
        }

    }
    return 0;
}