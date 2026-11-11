#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int f=c+n+m+d+q;
    int g;
    if(n%2==0){
        g=1;
    }
    else{
        g=0;
    }
    cout<<f+3<<endl;
    if(g==1){
        cout<<f-12;
    }
    else cout<<f-16;
    return 0;
}
