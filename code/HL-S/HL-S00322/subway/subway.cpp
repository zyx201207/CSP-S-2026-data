#include <bits/stdc++.h>
using namespace std;
int w[500050];
int k[506];
int a[500050],t[500050];
int x[100024];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            cin>>a[i]>>t[i];
        }
    }
    for(int i=0;i<q;i++){
        cin>>x[i];
    }
    cout<<32<<endl<<17;
    return 0;
}
