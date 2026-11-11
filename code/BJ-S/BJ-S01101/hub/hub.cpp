#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("migrate.in";"r";stdin);
    //freopen("migrate.out";"w";stdout);
    int c,t;
    cin>>c>>t;
    int n[t+1];
    int k[t+1];
    for(int z=1;z<=t;z++){
        cin>>n[z];
        cin>>k[z];
        int u[n[z]];
        int v[n[z]];
        fot(int i=1;i<=n-1;i++){
            cin>>u[i]>>v[i];
        }
        int (m=n[z]-1)/2
        m=m/2;
        if(k[z]==2){
            m=m/2+2;
        }
        if(k[z]>2){
            m=m/2+1
        }
        else{
            m=m+1;
        }
        cout<<m<<endl;
    }
    return 0;
}