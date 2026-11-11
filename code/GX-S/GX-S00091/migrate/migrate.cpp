#include<bits/stdc++.h>
using namespace std;
int c,T,n,d,a[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        int last=1;
        for(int i=2;i<=n;i++){
            while(a[i]-a[last]>d) last++;
            for(int j=last;j<=i-1;j++){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
        for(int i=1;i<=d;i++){
            cout<<0<<"\n";
        }
    }
    return 0;
}
