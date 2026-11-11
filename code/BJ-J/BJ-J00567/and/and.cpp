#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int maxx=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int s;
    for(int i=1;i<=n-m;i++){
        s=a[i];
        for(int j=2;j<=m;j++){
            s=s&a[i+j-1];
        }
        maxx=max(maxx,s);
    }
    cout<<s;
    return 0;
}
