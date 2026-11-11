#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,a[2000005],ans=0,t,c,st,w=0;
    long long d;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                for(int k=1;k<=d;k++){
                    if(j+k+d>=n)st++;
                }
            }
            if(st==2)ans++;
        }
        cout<<ans;
    }
    return 0;
}
