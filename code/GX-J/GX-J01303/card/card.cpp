#include <bits/stdc++.h>
using namespace std;
int p[500005];
int p2[500005];
int have[300005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m,b=0;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>p[i];
        if(b<p[i]){
            b=p[i];
        }
    }
    for(int i=1;i<=b;i++){
        cout<<i;
    }

    return 0;
}
