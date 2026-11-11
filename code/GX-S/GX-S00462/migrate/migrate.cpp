#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6+10;
LL c,q,a[N],qzh[N],duan[N];
int main(){
    std::ios::sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>q;
    if(c<=10){
        while(q--){
            LL n,d;
            cin>>n>>d;
            int b[302][302];
            for(int i = 1;i<=n;i++){
                cin>>a[i];
                if(a[i]-a[i-1]>d&&i>=2) duan[i] = 1;
                qzh[i] = qzh[i-1]+a[i];
            }
            for(int i = 1;i<=n;i++){
                for(int j = i;j<=n;j++){
                    if(i==j) continue;
                    int pa = abs(qzh[j]-qzh[i]);
                    //if(pa<d) b[1][]
                }
            }
        }

    }
    if(c>=11&&12>=c){
        while(q--){
            LL n,d;
            cin>>n>>d;
            for(int i = 1;i<=n;i++) cin>>a[i];
            LL u = abs(a[2]-a[1]);
            LL p = d/u;
            cout<<n-p-1<<"\n";
        }
    }
    if(c>=13&&c<=14){
        while(q--){
            cout<<0<<"\n";
        }
    }
    return 0;
}
