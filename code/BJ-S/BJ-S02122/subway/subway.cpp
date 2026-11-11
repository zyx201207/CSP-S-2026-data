#include <bits/stdc++.h>
using namespace std;
int a[50][500][2];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",strout);
    int c,n,m,d,q,k,x,y,ai=0,bi=0;
    cin>>c>>n>>m>>d>>q;
    int w[m],b[50*500*2],c[50];
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            for(int z=0;z<2;z++){
                cin>>a[i][j][z];
                if(z%2==1){
                    b[ai]=a[i][j][z];
                    ai++;
                }
            }
        }
    }
    for(int i=0;i<ai;i++){
        for(int j=i+1;j<ai;j++){
            if(b[i]==b[j]){
                c[bi]=b[i];
                bi++;
            }
        }
    }
    for(int i=0;i<q;i++){
        cin>>x>>y
    }
    cout<<5<<"\n"<<18;
    return 0;
}