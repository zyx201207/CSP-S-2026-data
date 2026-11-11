#include<bits/stdc++.h>
using namespace std;
int a[10000],b[10000];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,k;
    cin>>c>>k;
    while(k--){
        int m,n;
        cin>>m>>n;
        for(int i=1;i<=m;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
    }
    return 0;
}
