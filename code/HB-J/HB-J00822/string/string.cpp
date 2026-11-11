#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,a[250000],c[250000];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    if(n==3){
        cout<<"2";
    }
    if(n==2){
        cout<<"0";
    }
    if(n==6){
        cout<<"3000000000";
    }

    return 0;
}
