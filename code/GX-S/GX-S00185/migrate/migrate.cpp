#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate1.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d,x[20000000],s;
    bool flag[20000000];
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        for(int j=1;j<=n;j++){
            if(abs(x[j]-x[j-1]<=d)){
                flag[j]=true;
                s=j;
            }
            else{
                flag[j]=false;
                break;
            }
        }
        for(int x=1;x<=s;x++){

        }
    }
    return 0;
}
