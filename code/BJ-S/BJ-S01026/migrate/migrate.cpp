#include <bits/stdc++.h>
using namespace std;
int c,t;
struct node{
    int tra,id;
};
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        long long n,d,cnt,x[200010],t0;
        long long tra[200010],id[200010],tl=1,tf=1;
        scanf("%lld%lld",&n,&d);
        cin>>x[1];
        if(x[1]<0) t0=0-x[1];
        for(int i=2;i<=n;i++){
            scanf("%lld",&x[i]);
            x[i]+=t0;
        }for(int i=1;i<=n;i++){
            while(tra[tf]<x[i]&&tl!=tf){
                tf++;
            }
            tra[tl]=x[i]+(2*d-1);
            id[tl]=i;
            tl++;
            if(tra[tf]==x[i]){
                if(id[tf]-i<=d){
                    cnt++,tf++;
                }
            }
        }cout<<cnt<<"\n";
    }
    return 0;
}
