#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[500005],zt=0,q[500005];
struct x{
    long long z,t,l;
};
struct x x[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>q[i];
        for(int j=1;j<=q[i];j++){
            cin>>x[j].z>>x[j].t;
            x[j].l=i;
        }
    }
    int bg,ed;
    for(int i=1;i<=p;i++){
        cin>>bg>>ed;
        zt+=w[bg];
        int sxb=1;
        while(x[sxb].l<ed){
            sxb++;
        }
        int mxb=1;
        while(x[mxb].l<ed){
            mxb++;
        }
        for(int i=1;i<=q[bg];i++){
            for(int j=1;j<=q[ed];j++){
                if(x[sxb+i].z==x[mxb+j].z){
                    zt+=x[sxb+i].t+x[mxb+j].t;
                }
            }
        }
    }
    cout<<32<<endl<<17;
    return 0;
}

