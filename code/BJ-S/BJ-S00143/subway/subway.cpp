#include<bits/stdc++.h>
using namespace std;
struct{
    int iq,a[100005],t[100005];
}b[505];
long long m,w[100005],n,k[505],d,q,x,c,y,n1,n2,m1,m2,sum;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=2*k[i];j++){
            cin>>b[i].a[j]>>b[i].t[j];
            b[i].iq=i;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        for(int j=1;j<=n;j++){
            for(int l=1;l<=k[j];l++){
                if(b[j].a[l]==x){
                    n1=j;
                    n2=l;
                }
                else if(b[j].a[l]==y){
                    m1=j;
                    m2=l;
                }
            }
        }
        cout<<w[x]+w[y]<<endl;
    }
    return 0;
}
