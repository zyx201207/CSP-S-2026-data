#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
ll c,n,m,d,q,t1[N],t2[501][1001],a,b,e,be,ed,ans=0;//t2:lu xian + zhan tai
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>t1[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a;
        for(int j=1;j<=a;j++){
            cin>>b>>e;
            t2[i][b]=e;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>be>>ed;
        if(c<=11&&c>=7){
            ans+=t1[be];
            ans+=t1[ed];
            for(int j=1;j<=n;j++){
                if(t2[j][be]!=0){
                    ans+=t2[j][be];
                    for(int z=1;z<=m;z++){
                        if(t2[j][z]!=0){
                            be=z;
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
