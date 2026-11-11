 #include<bits/stdc++.h>
using namespace std;
long long a[2000006];
long long c,t,n,d,num,mj;

void dfs(int zd,int ans,int qd){
    if(zd==qd && ans==mj){
        num++;
        return ;
    }for(int i=a[zd]-a[zd-1];i<=d;i++){
        dfs(zd-i,++ans,qd);
    }
}
bool check(int i,int j){
    mj=0;
    for(int k=i;k<=j;k+=d){
        mj++;
    }num=0;
    dfs(j,0,i);
    if(num==1){
        return 1;
    }return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                ans+=(check(i,j)?1:0);
            }
        }cout<<ans;
    }
    return 0;
}

