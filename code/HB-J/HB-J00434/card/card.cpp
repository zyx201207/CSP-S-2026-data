#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int cnt[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<n;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    solve();
    return 0;
}
