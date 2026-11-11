#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int andd(int x,int y){
    if(x>y){
        swap(x,y);
    }
    int xx[35]={},yy[35]={},xp=0,yp=0,z=0;
    while(x>0){
        xx[++xp]=x%2;
        x/=2;
    }
    while(y>0){
        yy[++yp]=y%2;
        y/=2;
    }
    for(int i=xp;i>=1;i--){
        z*=2;
        if(xx[i]&&yy[yp-xp+i]){
            z++;
        }
    }
    return z;
}
long long f(bool b[N],int x,long long ans){
    if(x==m){
        return ans;
    }
    long long ma=0;
    for(int i=1;i<=n;i++){
        if(!b[i]){
            b[i]=1;
            ma=max(ma,f(b,x+1,andd(ans,a[i])));
            b[i]=0;
        }
    }
    return ma;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool b[N]={};
    long long ma=0;
    for(int i=1;i<=n;i++){
        if(!b[i]){
            b[i]=1;
            ma=max(ma,f(b,1,a[i]));
            b[i]=0;
        }
    }
    cout<<ma;
    return 0;
}
