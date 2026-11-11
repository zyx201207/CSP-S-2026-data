#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=2e6+5,mod=998244353;
const ll inf=1e18;
int c,t,n;
ll d,x[N],ans;
int mx[N],mx2[N],mx3[N];
ll calc(int l,int r){
    ll res=0;
    for(int i=l;i<=r;i++){
        res+=mx[mx2[i]]-mx[mx3[i]];
    }
    return res;
}
void solve(){
    cin>>n>>d;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    x[n+1]=4e18;
    for(int i=1,j=1;i<=n;i++){
        while(j<=n&&x[j]-x[i]<=d) j++;
        j--;
        mx[i]=j;
        mx2[i]=max(i,j-1);
        mx3[i]=max(i,j-2);
    }
    int lst=1;
    for(int i=1;i<=n;i++){
        if(x[i+1]-x[i]>d){
            ans+=calc(lst,i);
            lst=i+1;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    fastio
    cin>>c>>t;
    while(t --) solve();
    return 0;
}
/*
g++ migrate.cpp -o c
./c

*/