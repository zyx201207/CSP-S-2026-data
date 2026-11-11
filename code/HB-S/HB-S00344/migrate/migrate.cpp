#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
ll l,r,n,d,c,t,a[N];
ll cnt;
bool f(int x,int y){
    if(a[y]-a[x]<=d) return 0;
    if(a[y]-a[x+1]<=d&&a[x+1]-a[x]<=d){
        if(a[y]-a[y-1]<=d&&a[y-1]-a[x]<=d){
            return 1;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(l=1;l<=n-3;l++){
            r=l+3;
            if(f(l,r)){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
