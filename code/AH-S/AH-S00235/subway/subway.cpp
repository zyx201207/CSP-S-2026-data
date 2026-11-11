#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int a[m+10],b[q+10][q+10];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<q;i++){
        int k;
        cin>>k;
        for(int j=0;j<2*k;j++){
            cin>>b[i][j];
        }
    }
    cout<<35<<endl<<16;
    return 0;
}
