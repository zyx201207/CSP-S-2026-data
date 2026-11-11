#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
int mx;
int andd;
int b[200005];
int maxx;

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    int andd=a[1];
    for(int i=1;i<=n;i++){
        andd=andd&a[i];
        //cout<<a[i];
        b[i]=a[i];
        for(int j=1;j<=m;j++) b[i]=b[i]&a[i+j];
        maxx=max(maxx,b[i]);
    }
    if(m==1) cout<<mx;
    else if(m==n) cout<<andd;
    else cout<<maxx;

    return 0;
}
