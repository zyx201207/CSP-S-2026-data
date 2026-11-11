#include<bits/stdc++.h>
using namespace std;
struct nod{
int k,a,t,id;
}b[5005][5005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,p;
    int w[500005]={};
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i][0].k;
        for(int j=1;j<=b[i][0].k;j++){
            cin>>b[i][j].a>>b[i][j].t;
            b[i][j].id++;
        }
    }
    while(p--){
        int x,y,ans=0,f=0,h=0,f1=0,r=INT_MAX,q=0;
        cin>>x>>y;
        ans+=w[x];
        ans+=w[y];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=b[i][0].k;j++){
                if(b[i][j].a==x){
                        f=i;
                    ans+=b[i][j].t;
                    q++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=b[i][0].k;j++){
                if(b[i][j].a==y){
                        if(f!=i) h=1;
                        f1=i;
                    ans+=b[i][j].t;
                    q1++;
                }
            }
        }
        if(h==0){
            cout<<ans<<endl;
            continue;
        }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=b[i][0].a;j++){
                if(b[i][j].id!=1&&n-b[i][j].id==1){
                      r=min(b[i][j].t,r);
                }
            }
        }
        cout<<ans+r*2<<endl;
        }
    }
return 0;
}
