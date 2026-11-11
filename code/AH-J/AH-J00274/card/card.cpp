#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,f[500005],c,t[500005],x,a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        c++;
        f[i]+=c;
    }
    for(int i=1;i<=m;i++){
        cout<<f[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
