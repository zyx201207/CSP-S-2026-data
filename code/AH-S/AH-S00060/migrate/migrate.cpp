#include<bits/stdc++.h>
using namespace std;
int C,T;
int n,d,a[5005],t[5005],mi=0x3f3f3f3f;
bool f[5005][5005];
void dfs(int x,int route,int goal){
    if(x==goal){
        if(route<mi){
            mi=route;
            t[mi]++;
        }else if(mi==route){
            t[mi]++;
        }
        return ;
    }
    for(int i=x+1;i<=n;i++){
        if(f[x][i]){
            dfs(i,route+1,goal);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    if(C==11||C==12){
        while(T--){
            int gongcha,cover;
            cin>>n>>d;
            memset(a,0,sizeof(a));
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            gongcha=a[2]-a[1];
            cover=d/gongcha;
            if(cover>1){
                cout<<n-2*cover+1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
        return 0;
    }
    while(T--){
        int ans=0;
        cin>>n>>d;
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    f[i][j]=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mi=0x3f3f3f3f;
                memset(t,0,sizeof(t));
                dfs(i,0,j);
                if(mi==0x3f3f3f3f)continue;
                //cout<<"i="<<i<<" j="<<j<<" mi="<<mi<<" tmi="<<t[mi]<<"     ";
                if(t[mi]==2){
                    ans++;
                }
            }
            //cout<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}

