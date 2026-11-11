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
        int ch=x[1]-x[0];
        int ans=0;
        int p=d/ch;
        for(int j=0;j<n;j++){
            for(int i=j;i<n;i++){
                int s=(x[i]-x[j])/ch;
                if((p-s)>1)ans++;
            }
        }
        cout<<ans;
    }
}
