#include <bits/stdc++.h>
using namespace std;
long long a,b,c,_,l,x,d[128000];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int y;
    cin>>l;
    for(int i=1;i<=l;i++){
        cin>>x>>y;
        c+=x;
        for(long long jin=1;jin<=x;jin++){
            d[c+jin]=y;
        }
    }
    c=c/2+1;
    for(long long i2=1;i2<=l/2;i2++){
        if(d[1+i2]!=d[l-i2]){
            _++;
        }
    }
    cout<<_;
}
