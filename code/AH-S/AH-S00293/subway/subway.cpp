#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int c,n,m,d,q,minn,a[505][505],zt[505],ji[505],shu[505];
bool b1[505],b2[505];
 void dfs(int pos,int aim,int sum){
     if(pos==aim) minn=min(minn,sum);
     if(sum>=minn) return ;
    for(int i=1;i<=n;i++){
        if(a[i][pos]!=0&&b1[i]==0){
            for(int j=1;j<=m;j++){
                if(a[i][j]!=0&&b2[j]==0){
                    b1[i]=1,b2[j]=1;
                    dfs(j,aim,sum+a[i][pos]+a[i][j]);
                    b1[i]=0,b2[j]=0;
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>zt[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>ji[j]>>shu[j];
            a[i][ji[j]]=shu[j];
        }
    }
    for(int i=1;i<=q;i++){
        int sta,fin;
        cin>>sta>>fin;
        minn=0x3f3f3f3f;
        dfs(sta,fin,0);
        cout<<minn+zt[sta]+zt[fin]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
