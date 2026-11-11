#include<bits/stdc++.h>
using namespace std;
long long k=0,head[500009],w[500009],a[500009];
struct line{
    int to,w,pre;
};
line b[500009];
void add(int x,int y){
    k++;b[k].to=y;b[k].pre=head[x];head[x]=k;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,m,d,c,q,t;cin>>c>>t;
    for(int i1=1;i1<=t;i1++){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            add(a[i-1],a[i]);
        }
        m=a[2]-a[1];
        for(int i=1;i<=n;i++){
            if(a[i+1]-a[i]==m){
                if(m<=d){
                    if(n%d==1) cout<<n/d;
                    else cout<<n/d-1;
                    break;
                }
            }
            if(a[i+1]-a[i]>d) ans++;
            if(ans==n) cout<<"0";
        }

        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){

            }
        }*/
    }
    return 0;
}
