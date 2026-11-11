#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+10;
int n;
ll m,a[N];
bool f=1;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1&&a[i]!=a[i-1]) f=0;
    }
    if(f==1){
        cout<<n;
        return;
    }
    bool f2=1;
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
            f2=0;
        }
    }
    if(f2){
        ll cha=a[2]-a[1];
        ll t=0;
        int pos=1;
        while(t+cha<=m){
            t+=cha*pos;
            pos++;
        }
        cout<<pos-1;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int t=1;
    while(t--) solve();
    return 0;
}
