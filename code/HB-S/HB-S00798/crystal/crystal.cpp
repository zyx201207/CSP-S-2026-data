#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    ios::sync_with_stdio(false);
    long long mi=-999999;
    int an=0;
    int xian[n];
    cin >>n>>m;
    for(long long i=0;i<n;i++){
        cin>>xian[i];
    }
    for(long long i=0;i<n;i++){
        if(xian[i] < mi){mi=xian[i];}
    }
    mi=mi+m;
    for(long long i=0;i<n;i++){
        if(xian[i]>=mi){
                an+=1;
        }
    }
    cout << an;
    return 0;
}
