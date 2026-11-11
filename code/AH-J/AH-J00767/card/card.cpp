#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL>v;
const LL N=3e5+10;
LL b[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    LL n,m,x;
    cin>>n>>m;
    for(LL i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    b[0]=v[0];
    LL cnt=0;
    for(LL i=0;i<n;i++){
        if(b[cnt]!=v[i]){
            b[cnt++]=v[i];
        }
        else if(b[cnt]==v[i]){

        }
    }
    return 0;
}
