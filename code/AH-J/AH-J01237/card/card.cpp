#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],c[300005],t;
bool f[300005];
stack<long long> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]=i;
    }
    if(n==m){
        for(int i=1;i<=n;i++){
            b[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<b[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            b[a[j]]++;
            j=c[a[j]];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
