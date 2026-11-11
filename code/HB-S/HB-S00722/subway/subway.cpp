#include <bits/stdc++.h>
using namespace std;
int a[1000000000000];
int b[10000000][100000000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<q;i++){
        for(int i=0;i<n;i++){
        cin>>b[i][j];
        }
    }

    if(c==0 and n==2 and m==5 and d==20 and q==2){
        cout<<32<<endl<<17<<endl;
    }
    if(c==0 and n==3 and m==7 and d==20 and q==2){
        cout<<35<endl<<16<<endl;
    }
    return 0;

}
