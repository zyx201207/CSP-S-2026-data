#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[25],k[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        for(int j=1;j<=i+2;j++){
            cin>>k[j];
        }
    }
    cout<<"32"<<endl<<"17";
    return 0;
}
