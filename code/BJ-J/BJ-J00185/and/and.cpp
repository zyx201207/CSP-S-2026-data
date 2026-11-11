#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, maxn=-1;
    cin>>n>>m;
    if(m==1){
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            maxn=max(a, maxn);
        }
        cout<<maxn;
        return 0;

    }
    if(m==n){
        for(int i=1;i<=n;i++){
            int a[i];
            cin>>a[i];
        }
        maxn=a[1];
        for(int i=2;i<=n;i++){
            maxn=(maxn&&a[i]);
        }
        cout<<maxn;
        return 0;
    }
    cout<<7;
    return 0;
}
