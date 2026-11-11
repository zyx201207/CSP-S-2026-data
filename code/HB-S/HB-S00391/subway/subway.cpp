#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long c,n,m,d,q,q1;
long long w[N],a[N],t[N],x1[N],x2[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>q1;
        for(int j=0;j<q1;j++){
            cin>>a[j]>>t[j];
        }
    }
    for(int i=0;i<q;i++){
        cin>>x1[i]>>x2[i];
    }
    return 0;
}
