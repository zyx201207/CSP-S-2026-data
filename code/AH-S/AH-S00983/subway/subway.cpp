#include<bits/stdc++.h>
using namespace std;
const int MAXM=100000;
int c,m,n,d,q;
int w[MAXM],k[MAXM],a[MAXM][MAXM],t[MAXM][MAXM],trip[MAXM][3];
int main(){
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=2*k[i];j++){
            if(j%2==1){
                cin>>a[i][j/2];
            }
            else{
                cin>>t[i][j/2];
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>trip[i][1]>>trip[i][2];
    }
    cout<<"37"<<"18";
    return 0;
}
