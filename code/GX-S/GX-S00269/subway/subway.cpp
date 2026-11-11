#include <bits/stdc++.h>
using namespace std;
struct aj{
    int k;
    int x;
    int t;
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    aj a[1005];
    int a1[1005]={0},sum=0;
    if(n<=2){
        for(int i=1;i<=m;++i){
            cin>>a1[i];
        }
        for(int i=1;i<=n;++i){
            cin>>a[i].k;
            for(int j=1;j<=a[i].k;++j){
                cin>>a[j].x>>a[j].t;
            }
        }
       int f,d1;
       for(int i=1;i<=q;++i){
        cin>>f>>d1;
        for(int j=1;j<=a[i].k;++j){
            if(a[j].x==f){
                sum+=a[j].t;
                for(int l=j;l<=a[i].k;++l){
                    sum+=a[l].t;
                    if(a[l].x==d1){
                        cout<<sum;
                        return 0;
                    }
                }
            }
        }
       }
    }
    return 0;
}
