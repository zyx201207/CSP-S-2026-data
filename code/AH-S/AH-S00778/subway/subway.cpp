#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    int w[m]={0};
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    int k[n];
    for(int i=0;i<n;i++){
        cin>>k[i];
        int a[k[i]],t[k[i]];
        for(int j=0;j<k[i];j++){
            cin>>a[j]>>t[j];
        }
    }
    return 0;
}
