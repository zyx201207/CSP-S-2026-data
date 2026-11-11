#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ffor(i,a,b) for(ll (i)=(a);(i)<(b);++(i))
ll a[500500];
ll res[500500];
bool vst[500500];
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    ffor(i,0,n)cin>>a[i];
    ffor(i,0,n){
        fill(vst,vst+n,false);
        ffor(j,i,n) if(!vst[a[j]]) res[a[j]]++;
    }
    ffor(i,0,m) cout<<res[m]<<" ";
    return 0;
}