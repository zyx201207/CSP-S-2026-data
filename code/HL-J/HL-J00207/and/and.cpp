#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,x,y=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x>y)y=x;
    }
    cout<<y;
    return 0;
}
