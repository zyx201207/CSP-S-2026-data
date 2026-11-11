#include<bits/stdc++.h>
using namespace std;
int n,m,d=0,e;
int a[500000],b[500000],c[300000];
int x(int j){
    for(int i=j+1;i<n;++i){
        if(a[j]==a[i]){
            e=i;
            return i;
        }
    }
    return 0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        b[500000]={0};
        for(int j=i;j<n;++j){
            b[d]==a[j];
            d++;
            if(x(j)){
                j=e;
            }
        }
        for(int j=0;j<d;++j){
            c[b[j]]++;
        }
    }
    for(int i=0;i<m;++i){
        cout<<c[i];
    }
    return 0;
}
