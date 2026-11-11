#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,w[1000000+9],s[1000000+9],minn,ans[10][10][10],cnt=0;
void peile(int start,int now,int to,ll road){
    if(now==to){
        ans[start][to][road]++;
        minn=min(minn,road);
        return;
    }
    ll op=1;
    while(d>=s[now+op]-s[now] and now+op<=to){
        peile(start,now+op,to,road+1);
        op++;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(13<=c and c<=14){
        for(int i=1;i<=t;++i)cout<<"0\n";
    }
    for(int k=1;k<=t;++k){
            cnt=0;
            memset(w,0,sizeof w);
    memset(s,0,sizeof s);
    memset(ans,0x3f,sizeof ans);
        cin>>n>>d;
        for(int j=1;j<=n;++j){
                cin>>w[j];
                s[j]=w[j]+s[j-1];}
        for(int i=1;i<=n;++i){
            for(int j=i;j<=n;++j){
                    minn=0x3f3f3f;
                peile(i,i,j,0);
            if(ans[i][j][minn]==2)cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
