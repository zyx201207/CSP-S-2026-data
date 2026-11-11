#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,x[99999],n,d,m[99999];
    cin>>c>>t;
    for(int j=0;j<t;j++){
            int ans=0,e=0;
            cin>>n>>d;
            for(int i=0;i<n;i++){
                cin>>x[i];
            }
            for(int a=0;a<n;a++){
                    e=0;
                for(int b=1;b<n;b++){
                    if(x[b]-x[a]<=d&&x[b]-x[a+1]<=d){
                    m[e]=x[b]-x[a];
                    e++;
                    }
                }
                if(m[e]>m[e-1]){
                    ans++;
                }
            }
            if(j<t){
            cout<<ans<<endl;
            }
            else{
                cout<<ans;
            }
    }
    return 0;
}
