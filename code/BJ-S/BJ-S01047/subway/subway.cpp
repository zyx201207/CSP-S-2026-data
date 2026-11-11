#include <bits/stdc++.h>
using namespace std;
using ll=long long;


//quanju
ll w[500020];           //zhantingdoditiekoushijian
ll qd[100020];             //chuxingjihuadiaidan
ll zd[100020];             //chuxingjihuazhongdian
ll zhanshu[520];         //meitioaditiezhanshu

//20-21
//ll sub[3][500020];   //ditiejingguozhan
ll tim[500020][3];   //ditiejingguozhandaozhantaishijian
bool jingguo[500020][3];




int main() {
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    if(n==1) {
        for(int i=1;i<=m;i++) cin>>w[i];
        //for(int i=1;i<=n;i++) {
            cin>>zhanshu[1];
            int temp123;
            for(int j=1;j<=zhanshu[1];j++) cin>>temp123>>tim[j][1];
        //}
        for(int i=1;i<=q;i++) {
            cin>>qd[i]>>zd[i];
            cout<<w[qd[i]]+w[zd[i]]+tim[qd[i]][1]+tim[zd[i]][1]<<endl;
        }
        return 0;
    }
    //if(c==20||c==21) {
        for(int i=1;i<=m;i++) cin>>w[i];
        for(int i=1;i<=n;i++) {
            cin>>zhanshu[i];
            for(int j=1;j<=zhanshu[i];j++) {
                ll bianhao,shijian;
                cin>>bianhao>>shijian;
                jingguo[bianhao][i]=1;
                tim[bianhao][i]=shijian;
            }
        }
        for(int i=1;i<=m;i++) {
      //      cout<<jingguo[i][1]<<jingguo[i][2]<<endl;
        }
       // cout<<endl<<endl;
        for(int i=1;i<=q;i++) {
            cin>>qd[i]>>zd[i];
        }

    for(int j=1;j<=q;j++) {
        bool flag=1;
        ll ans=1e19;
        for(int i=1;i<=n;i++) {

            if(jingguo[qd[j]][i]==1&&jingguo[zd[j]][i]==1){
                ans=min(ans,w[qd[j]]+w[zd[j]]+tim[qd[j]][i]+tim[zd[j]][i]);
                flag=0;
            }
        }
        if(flag=0){
                cout<<ans<<endl;
                continue;
        }
        //ll ans=1e19;
        for(int i=1;i<=m;i++) {
            //for(int j=1;j<=m;j++) {
                if(jingguo[i][1]&&jingguo[i][2]) {
                        //
                        cout<<i<<endl;
                    ans=min(ans,tim[i][1]+tim[i][2]);
                }
            //}
        }
        if(jingguo[qd[j]][1])ans+=(w[qd[j]]+w[zd[j]]+tim[qd[j]][1]+tim[zd[j]][2]);
        else ans+=(w[qd[j]]+w[zd[j]]+tim[qd[j]][2]+tim[zd[j]][1]);
        cout<<ans<<endl;
    }
    //}

    return 0;
}
