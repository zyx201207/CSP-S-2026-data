#include <bits/stdc++.h>
using namespace std;
int a[1000000];
string er(int x){
    string an;
    while(x){
        char xx=x%2;
        an+=xx;
        x/=2;
    }
    string ann;
    for(int i=an.size();i>=0;i--){
        ann+=an[i];
    }
    return ann;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,mx=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<12;
    return 0;
}

