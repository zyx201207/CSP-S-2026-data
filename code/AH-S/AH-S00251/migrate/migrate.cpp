#include<iostream>
using namespace std;
int c,t,n,m,x[2000005],minn,cs,cnt;
void dfs(int a,int y,int sj){
    if(a==y){
        if(minn>sj){
            minn=sj,cs=1;
        }else if(minn==sj){
            cs++;
        }else{

        }
        return ;
    }
    for(int i=a+1;i<=y;i++){
        if(x[i]-x[a]<=m){
            dfs(i,y,sj+1);
        }else{
            return ;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cnt=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                minn=0x3f3f3f3f;
                cs=1;
                dfs(i,j,0);
                if(cs==2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
