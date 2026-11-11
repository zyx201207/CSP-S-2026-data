#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,sr,x,y;
int w[25];
int ta[25],tb[25],tc[25];
int dt[550][25];
int dfs(int x,int y,int xl,int cnt){
    if(dt[xl][x]!=0&&dt[xl][y]!=0){
        return cnt;
    }cnt++;
    for(int i=1;i<=n;i++){
        if(dt[i][y]!=0){
            return dfs(x,y,i,cnt);
        }
    }return 0;
}
int zc(int x,int y,int xl,int cnt){
    if(dt[xl][x]!=0&&dt[xl][y]!=0){
        return cnt;
    }
    for(int i=1;i<=n;i++){
        if(dt[i][x]!=0){
            for(int j=1;j<=m;j++){
                if(dt[i][j]!=0&&j!=x){
                    cnt+=dt[i][j]+dt[i][x];
                    return zc(j,y,i,cnt);
                }
            }
        }
    }return 0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    if(c==20||c==21||n<=2){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }for(int i=1;i<=n;i++){
            if(i==1){
                scanf("%d",&k);
                for(int j=1;j<=k;j++){
                    scanf("%d",&sr);
                    scanf("%d",&ta[sr]);
                }
            }
            else {
                scanf("%d",&k);
                for(int j=1;j<=k;j++){
                    scanf("%d",&sr);
                    scanf("%d",&tb[sr]);
                }
            }
        }long long min1=10000000000;
        for(int i=1;i<=m;i++){
            if(ta[i]!=0&&tb[i]!=0){
                if((ta[i]+tb[i])<min1) min1=ta[i]+tb[i];
            }
        }for(int i=1;i<=q;i++){
            scanf("%d %d",&x,&y);
            if((ta[x]!=0&&ta[y]!=0)||(tb[x]!=0&&tb[y]!=0)){
                cout<<w[x]+w[y];
            }else{
                cout<<w[x]+w[y]+min1;
            }
        }return 0;
    }if(7<=n&&n<=11){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&k);
            for(int j=1;j<=n;j++){
                scanf("%d",&sr);
                scanf("%d",&dt[i][sr]);
            }
        }for(int i=1;i<=q;i++){
            scanf("%d %d",&x,&y);
            int t=w[x]+w[y];
            cout<<t+sr*2;
        }return 0;
    }
    if(12<=n&&n<=19){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&k);
            for(int j=1;j<=n;j++){
                scanf("%d",&sr);
                scanf("%d",&dt[i][sr]);
            }
        }for(int i=1;i<=q;i++){
            scanf("%d %d",&x,&y);
            int t=w[x]+w[y];
            for(int i=1;i<=n;i++){
                if(dt[i][y]!=0){
                    sr=dfs(x,y,i,0);
                    break;
                }
            }cout<<t+sr*2;
        }return 0;
    }
    fclose(stdin);
    fclose(stdout);
}

