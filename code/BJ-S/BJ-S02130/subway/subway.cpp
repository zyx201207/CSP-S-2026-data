#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,l;
long long w[50005],t[505][50005],k[505];
bool x[50005][505],a[505][50005];//zhanjingguoxian xianjingguozhan
long long ans;
bool zhan[50005],xian[505];//shifouzouguo
long long o,b;//jihua
void pan(long long t){
    ans=min(t,ans);
    cout<<"0"<<endl;
}
void dfs(bool p,long long o,long long b,long long k){

    if(p==0){//zhan
            cout<<"zhan"<<o<<endl;
        if(o==b){
            pan(k);
            return ;
        }
        for(long long i=1;i<=505;i++){
            if(!x[o][i]) continue;
            if(!xian[i]){
                xian[i]=1;
                dfs(1,i,b,k+t[o][i]);
                xian[i]=0;
            }
        }
        return ;
    }
    else{
        cout<<"xian"<<o<<endl;
        for(long long i=1;i<=50005;i++){
            if(!a[o][i]) continue;
            if(!zhan[i]){
                zhan[i]=1;
                dfs(0,i,b,k+t[o][i]);
                zhan[i]=0;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;//biaohao,xianshu,zhanshu,lushu,jihuashu
    for(int i=1;i<=m;i++){
        cin>>w[i];//zhan
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){//zhanshu
            cin>>l>>t[i][j];
            a[i][j]=1;//ixianshangyoujzhan
            x[j][i]=1;//jzhanzaiixianzhong
        }
    }
    while (q--){
        ans=100000000;
        memset(zhan,0,sizeof(zhan));
        memset(xian,0,sizeof(xian));
        cin>>o>>b;
        zhan[o]=1;
        dfs(0,o,b,0);//dangqianzhanhuoxian zhan0xian1 dnagqian mubiao shijian
        ans+=w[o];
        ans+=w[b];
        cout<<ans<<endl;
    }
    return 0;
}

     /*                aaaaaaa
                    aaaaaaaaaaa
                aaaaaaaaaaaaaaaaaa
             aaaaaaaa       aaaaaaaaa
          aaaaaaaa              aaaaaaaaa
          aaaaaaaa              aaaaaaaaa
        aaaaaaaa                  aaaaaaaaa
        aaaaaaaa                  aaaaaaaaa
        aaaaaaaa                  aaaaaaaaa
        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
        aaaaaaaaa                  aaaaaaaa
        aaaaaaaa                   aaaaaaaa
        aaaaaaaaa                  aaaaaaaa





        kkkkkkk             kkkkkkk
        kkkkkkk            kkkkkkk
        kkkkkkk          kkkkkkk
        kkkkkkk        kkkkkkk
        kkkkkkk       kkkkkkk
        kkkkkkk     kkkkkkkk
        kkkkkkk  kkkkkkkk
        kkkkkkkkkkkkkkk
        kkkkkkk  kkkkkkkk
        kkkkkkk     kkkkkkkk
        kkkkkkk       kkkkkkkk
        kkkkkkk           kkkkkkkk
        kkkkkkk              kkkkkkk
        kkkkkkk               kkkkkkkk
        kkkkkkk                kkkkkkk
        */
