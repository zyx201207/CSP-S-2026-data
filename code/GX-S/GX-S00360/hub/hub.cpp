#include<bits/stdc++.h>
using namespace std;
int uone[10000];
int utwo[10000];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,k;
    for(int j=1;j<=t;j++){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            cin>>uone[i]>>utwo[i];
        }
    }
    return 0;
}
