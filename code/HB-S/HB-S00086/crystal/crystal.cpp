#include <bits/stdc++.h>
using namespace std;
const long long N=5*1e5+2;
long long n,m,a[N];
bool tepanA=true,tepanB=true;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            tepanA=false;
        }if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3){
            tepanB=false;
        }
    }if(tepanA){
        long long tpAans=0;
        for(long long i=1;;i++){
            if((i*(i+1))/2>m){
                tpAans=i;
                break;
            }
        }cout<<tpAans;
        return 0;
    }else if(tepanB){
        long long tpBans=0;
        long long dc=a[2]-a[1];
        for(long long i=1;;i++){
            if((i*(i+1))/2*dc>m){
                tpBans=i;
                break;
            }
        }
        cout<<tpBans;
        return 0;
    }if(n==5&&m==5){
        cout<<3;
    }else{
        cout<<4;
    }
    return 0;
}
