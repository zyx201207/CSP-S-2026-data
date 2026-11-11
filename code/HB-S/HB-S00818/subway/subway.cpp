#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
struct zhan{
    int next[10005];
    long long ting;
}z[10005];
struct xian{
    int z1,z1t;
    int z2,z2t;
}x[1000005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway,out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c>=7&&c<=11){
        for(int i;i<=m;i++){
            cin>>z[i].ting;
        }
        for(int j=1;j<=n;j++){
            int a;cin>>a;
            for(int i=1;i<=a;i++){
                cin>>x[i].z1>>x[i].z1t>>x[i].z2>>x[i].z2t;

            }
        }
    }

return 0;
}
