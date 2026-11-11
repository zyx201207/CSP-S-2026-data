#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[5000];
int md[5000];
int sz[5000000];
int ser(int nume,int kk){
    if(nume==n){
        ans[sz[nume]]++;
        return 0;
    }
    if(md[sz[nume]]==nume){
        ans[sz[nume]]++;
        ser(nume+1,kk);
        return 0;
    }
    ans[sz[nume]]++;
    if(md[sz[nume]]!=n)
    ser(md[sz[nume]]+1,kk);
    return 0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>sz[i];
        md[sz[i]]=i;
    }
    for(int i=1;i<=n;i++){
        ser(i,i);
    }

    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
