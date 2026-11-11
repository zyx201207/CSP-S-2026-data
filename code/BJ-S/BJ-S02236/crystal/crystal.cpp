#include<bits/stdc++.h>
using namespace std;
int n;
long long m,cnt,T,x,y;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m>>x>>y;
    if (x>y){
        T=x-y;
    }
    else T=y-x;
    for (int i=1;;i++){
        if ((i*i+i)/2<m&&(i*i+3*i+2)/2>m){
            cnt=(i+1)/T;
            break;
        }
        else if ((i*i+i)/2==m){
            cnt=(i+1)/T;
            break;
        }
    }
    if (m>=(n*n-n)/2){
        cout<<n;
    }
    else{
        cout<<cnt;
    }
    return 0;
}