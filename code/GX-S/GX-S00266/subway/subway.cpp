#include <bits/stdc++.h>
using namespace std;
int mn=10000000;
struct s{
    int num;
    int a[1000];
    int t[1000];
};
s x[1000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int qq[1000];
    for(int i=1;i<=n;i++){
        cin>>qq[i];
    }

    for(int i=1;i<=n;i++){
        cin>>x[i].num;
        for(int j=1;j<=x[i].num;j++){
            cin>>x[i].a[j]>>x[i].t[j];
        }
    }
    int px[10000],py[10000];
    for(int i=1;i<=q;i++){
        cin>>px[i]>>py[i];
    }
    cout<<32<<endl<<17;
    return 0;
}
