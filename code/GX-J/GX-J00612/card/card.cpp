#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],t[300005],b[300005],c[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool flag = 1;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        t[a[i]]++;
        flag=(a[i]>=a[i-1]);
        c[a[i]]=i;
    }
    for(int i = 1; i <= m; i++){
        b[i]=t[i]+b[i-1];
    }
    if(flag){
        for(int i = 1; i <= m; i++){
            cout<<b[i]<<' ';
        }
    }
    else if(n==m){
        for(int i = 1; i <= m; i++){
            cout<<c[i]<<' ';
        }
    }
    else{
        for(int i = 1; i <= m; i++){
            cout<<b[i]<<' ';
        }
    }
    return 0;
}
