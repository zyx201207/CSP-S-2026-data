#include<bits/stdc++.h>
using namespace std;
int n,m,s[500009],zh[300009],sx[300009],ans[300009];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int a=1;a<=n;a++){
        cin>>s[a];
    }
    for(int a=n;a>=1;a--){
        if(!zh[s[a]]){
            zh[s[a]]=a;
        }
    }
    if(m>100000){
        for(int a=1;a<=m;a++){
            cout<<zh[a]<<" ";
        }
        return 0;
    }
    for(int ks=1;ks<=n;ks++){
        for(int a=ks;a<=n;a++){
            if(!sx[s[a]]){
                sx[s[a]]=true;
                ans[s[a]]++;
            }
            if(a!=zh[s[a]]){
                a=zh[s[a]];
            }
        }
        for(int a=1;a<=m;a++){
            sx[a]=false;
        }
    }
    for(int a=1;a<=m;a++){
        cout<<ans[a]<<" ";
    }
    return 0;
}