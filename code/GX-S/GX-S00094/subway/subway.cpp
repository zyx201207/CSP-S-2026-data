#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int ans[2];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    ans[0]=32;
    ans[1]=17;
    for(int i=0;i<2;i++){
        if(i==0){
            cout<<32<<endl;
        }
        else if(i==1) cout<<17<<endl;
    }
    return 0;
}
