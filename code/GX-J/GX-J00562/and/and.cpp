#include<bits/stdc++.h>
using namespace std;
bool am(int x,int y,int z,int v[10005]){
    for(int i=1;i<=y;i++){
        if(v[i]>x){
            x=v[i];
            z=i;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b[10005],c,ma=0,wei=0;
    cin>>a>>c;
    for(int i=1;i<=a;i++){
        cin>>b[i];
        if(b[i]>ma){
            ma=b[i];
            wei=i;
        }
    }
    int d=ma;
    for(int j=1;j<=c-1;j++){
        ma=0;
        b[wei]=0;
        d=d&am(ma,a,wei,b);
    }
    cout<<d;
    return 0;
}
