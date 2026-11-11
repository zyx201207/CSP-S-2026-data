#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mx=300000005,N=500005;
bool b[mx];
int ans[mx],a[N],n,m;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    if(m<=2){
        int all=0,bll=0;
        for(int i=1;i<=n;++i){
            int sa=0,sb=0,za=0,zb=0,zza=0,zzb=0;
            for(int j=i;j<=n;++j){
                if(a[i]==1) ++sa,zza=za,za=i;
                else ++sb,zzb=zb,zb=i;
            }
            if(sa%2==0){
                if(zb>za&&sb%2!=0) ++bll;
            }else{
                if(sb%2==0) if(za>zb) ++all;
                if(sb%2!=0){
                    if(zza>zb) ++all;
                    else if(zzb>za) ++bll;
                    else if(za>zzb&&zb>zza) ++all,++bll;
                }
            }
        }
        cout<<all<<" "<<bll;
    }
    return 0;
}
