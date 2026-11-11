//bi-solve
#include <bits/stdc++.h>
using namespace std;
const int LEN=5e5+5;
typedef long long int ll;
int c,n,m,d,q;
int w[LEN];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    //cout<<ans;
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        cout<<(i+1)%2;
    }
    return 0;
}
