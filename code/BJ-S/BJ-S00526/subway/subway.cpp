#include <bits/stdc++.h>
using namespace std;
int w[500005];
struct xian{
    int k;
    int a[500005],t[500005];
} x[500];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>x[i].k;
        for(int j=0;j<x[i].k;j++){
            cin>>x[i].a[j]>>x[i].t[j];
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        int sum=0;
        sum+=w[a-1];
        for(int i=0;i<n;i++){
            for(int j=0;j<x[i].k;j++){
                if(x[i].a[j]==a-1){

                }
            }
        }
    }

    return 0;
}