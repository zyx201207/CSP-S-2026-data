#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000006],cnt,mn,ans,d,n;
void bfs(long long nw,long long tgt,long long ct){//cout<<nw<<" "<<tgt<<" "<<ct<<endl;
    if(mn!=-1 and ct>mn){
        return ;
    }//cout<<"qwq";
    if(nw>tgt)return ;
    if(tgt==nw){//cout<<"owo";
        if(mn==-1 or ct<mn){
            cnt=1;
            mn=ct;
            return ;
        }
        else {if(ct==mn)cnt++;}return ;}
    for(int ii=1;ii<=n;ii++){
        if(a[nw+ii]-a[nw]>d)break;
        bfs(nw+ii,tgt,ct+1);
    }
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                   // cout<<i<<" "<<j<<endl;
                cnt=0;
                mn=-1;
                bfs(i,j,0);
                //cout<<i<<" "<<j<<" ."<<cnt<<endl;
                if(cnt==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}