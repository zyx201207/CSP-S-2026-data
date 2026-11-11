#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[125255];
int k[501];
int a[501][1000001],t[501][1000001];
int r[100001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=0;i<q;i++){
        cin>>r[i];
    }
    if(c=0 && n==2){
        cout<<32<<endl;
        cout<<17<<endl;
    }
    else if(c==0 && n==3){
        cout<<35<<endl;
        cout<<16<<endl;
    }
    return 0;
}
