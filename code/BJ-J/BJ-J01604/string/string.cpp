#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string k;
    int n,minn=10000,a[10001];
    char b[100001];
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>b[i];
        if(a[i]<minn)minn=a[i];
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    bool is=1;
    for(int i=2;i<=n;i++){
        if(b[i]!=b[i-1]){
            is=0;
            break;
        }
    }
    if(is){
        cout<<0;
        return 0;
    }
    if(n==2){
        cout<<minn;
        return 0;
    }
}
