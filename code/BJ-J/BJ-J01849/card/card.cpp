#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[555555],c[555555],d[555555];
    bool b[555555];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=false;
        c[i]=0;
        d[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[a[j]]==true){
               for(int k=j-1;k>c[a[j]];k--){
                 b[a[k]]=false;
               }
               c[a[j]]=j;
            }
            else{
                b[a[j]]=true;
                c[a[j]]=j;
            }
        }
        for(int j=1;j<=n;j++){
            if(b[j]==true){
                d[j]++;
            }
            b[j]=false;
            c[j]=0;
        }
    }
    for(int j=1;j<=m;j++){
        cout<<d[j]<<" ";
    }
    return 0;
}
