#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n[1001],k[1001];
struct cityroad{
    long long num;
    long long cango[101];
    long long gole=0;
}cities[1001][1001];
long long q,r;
void connect(long long I,long long Q,long long R){
    cities[I][Q].cango[++cities[I][Q].gole]=R;
    cities[I][R].cango[++cities[I][Q].gole]=Q;
}
long long distnc(long long I,long long le,long long ri){
    if(le==ri) return 0;
    for(long long i=1;i<=cities[I][le].gole;i++){
        if(cities[I][le].cango[i]==ri){
            return 1;
        }
    }
}
int main(){
    cin>>c>>t;
    for(long long i=1;i<=t;i++){
        cin>>n[i]>>k[i];
        for(long long j=1;j<=n[1];j++){
            cities[i][j].num=j;
        }
        for(long long j=1;j<n[1];j++){
            cin>>q>>r;
            connect(i,q,r);
        }
    }
    return 0;
}
