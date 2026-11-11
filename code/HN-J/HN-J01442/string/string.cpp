#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    int a;
    cin>>a;
    int d=0;
    string c[a];
    int b[a];
    string e;
    for(int i=0;i<a;i++){
        cin>>b[i]>>c[i];
        d+=b[i];
        for(int j=0;j<b[i];j++){
            e+=c[i];
        }
    }
    if(d%2==1){
        d=d-1;
    }
    int x=d/2;
    char f[x];

    for(int i=0;i<x;i++){
        f[i]==e[i];
    }
    int z=0;
    for(int i=x;i>0;i--){
        if(f[i]!=e[i]){
            z++;
        }
    }
    cout<<z;
    return 0;
    }
