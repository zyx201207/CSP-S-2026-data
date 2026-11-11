//GZ-S00426 遵义市第一中学 瞿才涵
#include<bits/stdc++.h>
using namespace std;

int o(long long x,long long y,long long feet){
    int sum=0;
    if(x==y) return 1;
    else if(y<x) return 0;
    else{
        for(int i=1;i<=feet;i++){
            return sum+=(o(x,y-i,feet));
        }
    }

    return sum;
}   

struct fly{
    long long place,list,time;
};

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long c,t;
    cin >>c>> t;
    fly f[t+1]={0};
    long long a[t+1][105]={0};
    for(long long  i=1;i<=t;i++){
        cin >> f[i].list>>f[i].time;
        for(long long  j=1;j<=f[i].list;j++){
            cin >> a[f[i].list][j];
        }
    }

    cout << o(1,4,2);


    return 0;
}