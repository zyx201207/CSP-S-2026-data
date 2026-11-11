#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200009],ma=0,hma=21000009,maa;
void ccp(){
    cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            ma=max(ma,a[i]);
        }
        if(m==1){
            cout<<ma;
            return;
        }
        for(int i=0;i<m;i++){
                ma=0;
                for(int o=0;o<n;o++){
                    if(a[o]<21000009) ma=max(ma,a[o]);
                    if(ma==a[o]) maa=o;
                }
                a[maa]=21000009;
                if(hma==21000009){
                    hma=ma;
                }else{
                    hma=hma & ma;
                }
        }
        cout<<hma;
        return;
}
int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ccp();
    return 0;
}