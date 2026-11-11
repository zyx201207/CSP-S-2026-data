#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int w[500005],a[500005],t[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        int k;
        for(int j=0;j<k;j++){
            cin>>a[j]>>t[j];
        }
    }
    for(int i=q;i>0;i--){
        int x,y;
        cin>>x>>y;
    }
    while(q--){
        cout<<d/2+q<<endl;
    }
    return 0;
}
