#include<bits/stdc++.h>
using namespace std;
long long wh[2000010];long long k[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    //cout<<3-(-2);
    if(c==0){
        cout<<1<<'\n'<<2;
        return 0;
    }
    while(t--){
        int n,d;
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;++i){
            scanf("%lld",wh+i);
            //wh[i]+=1e18;
            //cout<<wh[i]<<'\n';
        }for(int i=1;i<=n;++i){
            //cout<<i<<' ';
            if(i<=n-3&&wh[i+2]-wh[i]<=d&&wh[i+3]-wh[i+1]<=d&&wh[i+3]-wh[i]>d/*&&((i==1)||wh[i]-wh[i-2]>d)*/){
                k[i]=1;
            }else k[i]=0;
            if(wh[i]-wh[i-1]<=d)k[i]+=k[i-1];
            //cout<<k[i]<<' ';
        }//k[0]=k[1];
        long long su=0;
        for(int i=1;i<=n-3;++i){
            for(int j=i+3;j<=n;++j){
                if(k[j]-k[i-1]==1){
                    ++su;
                    //cout<<j<<' '<<i<<'\n';
                }
                /*int o=0;
                for(int l=i;l<=j;++l){
                    if(k[l])++o;
                    if(o>1)break;
                }if(o==1)++su;*/
            }
        }printf("%lld\n",su);
    }return 0;
}