#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll ai[514514];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> ai[i];
    }
    sort(ai+1,ai+n+1);
    ll maxnum=0;
    for(int i=1;i<=n;i++){
        ll maxm=0;
        for(int j=1;j<=i;j++){
            maxm+=ai[i]-ai[j];
        }
        if(maxm>m) continue;
        maxnum=i;
    }
    cout << maxnum << endl;
    return 0;
}
