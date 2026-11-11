#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int t=0;
    int w=0;
    int o=0;
    int hkx=0;

    string m;
    cin>>n;
    string a[n];
    int p;
    string l[100];
    string g[100];
    for(int i=1;i<=n;i++){
        cin>>p>>m;
        for(int j=t;j<t+p;j++){
            l[j]=m;
        }
        t+=p;

    }


    for(int i=t-1;i>=0;i--){
        g[o]=l[i];
        o++;
    }
    for(int i=0;i<t;i++){
        if(l[i]!=g[i]){
            w++;
        }
    }
    cout<<w/2;
    return 0;
}
