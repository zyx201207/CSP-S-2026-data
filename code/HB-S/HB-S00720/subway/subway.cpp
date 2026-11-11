#include <bits/stdc++.h>
using namespace std;
long long c,n,m,q,d,t1[10010],t2[10010],qd,zd,zzs=0,jh[2],zs=0,hczz=0;
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
    cin>>t1[i];
}
for(int i=0;i<n;i++){
    int hcz;
    cin>>hcz;
    hczz+=hcz;
    for(int j=0;j<hcz*2;j++){
        int hct;
        cin>>hct;
        t2[zs]=hct;
        zs++;
    }
}
for(int k=0;k<q;k++){
        zzs=0;
    cin>>jh[0]>>jh[1];
    for(int i=0;i<hczz*2;i+=2){
        if(t2[i]==jh[0]){
            qd=i;
        }
        if(t2[i]==jh[1]){
            zd=i;
            break;
        }
    }
    for(int i=qd+2;i<=zd-2;i+=2){
        for(int j=i+2;j<=zd-2;j+=2){
            if(t2[i]==t2[j]){
                zzs+=t2[i+1]+t2[j+1];
                i=j;
                break;
            }
        }
    }
    cout<<zzs+t1[jh[0]]+t2[qd+1]+t1[jh[1]]+t2[zd+1];
}

return 0;}
