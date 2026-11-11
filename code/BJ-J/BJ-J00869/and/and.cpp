#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int f[5+n],k=0,win=-10000000;
    for(int i=1;i<=n;i++){
        cin>>f[i];}
    if(m=1){
        for(int i=1;i<=n;i++){
            win=max(win,f[i]);

    }}


    if(m=2){
    for(int i=1;i<=n;i++){
        k=f[i];
        for(int j=1;j<=n;j++){
                if(i!=j)
            win=max(win,k & f[j]);

        }
    }}
    if(m=n)
        for(int i=1;i<=n;i++){
        win=win & f[i];
        }
    cout<<win;
    return 0;

}
