#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],a[500][500005],x[500005],y[500005],s,k[100000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            cin>>s;
            cin>>a[n][s];
            m=a[n][s];
        }
    }
    for(int i=0;i<q;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<q;i++){
        cout<<w[x[i]]+w[y[i]]+m*2<<endl;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
