#include<bits/stdc++.h>
using namespace std;
const long long N=1e7+5;
long long n,m,maxa=1;
long long a[N];
bool check(long long c,int i){
    long long tot=m;
    bool ok=0;
    for(int j=i-1;j>=1;j--){
        if(tot>=(a[i]-a[j])){
                tot=tot-(a[i]-a[j]);
                ok=1;
        }
        else{
            ok=0;
            break;
        }
    }
    return ok;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(check(a[i],i))maxa=i;

    }
    cout<<maxa;
    return 0;
}
