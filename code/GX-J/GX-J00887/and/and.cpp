#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
    freopen("and.cpp","r",stdin);
    freopen("and.cpp","w",stdout);
    int n,m;
    int a[200000+5];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int s=a[1]&a[2];
    if(m==n){
        for(int i=3;i<=m;i++){
            s=s&a[i];
        }
        cout<<s;
    }
    int l=-2e30-1;
    if(m==1){
        for(int i=1;i<=n;i++){
            l=max(l,a[i]);
        }
        cout<<l;
    }

    return 0;
}
