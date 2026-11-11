#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500050],k[520],a[520][50005],t[520][50005];
int tub[500050],tu[500050][52][2],minn=2147483647;
int tu2[500050][55],tt;
int sta,las;
bool tuinit[500050];
void dfs1(int x,int sumtime){
    if(x==las){
        if(sumtime<minn){
            minn=sumtime;
        }
        return ;
    }
    for(int i=1;i<=tub[x];i++){
        if(!tuinit[tu[x][i][0]]){
            tuinit[tu[x][i][0]]=1;
            dfs1(tu[x][i][0],sumtime+tu[x][i][1]);
            tuinit[tu[x][i][0]]=0;
        }
    }
    return ;
}
void dfs2(int x,int num){
    //cout << x << ' ' << num << '\n';
    if(x==las){

        if(num<minn){
            minn=num;
        }
        return ;
    }
    for(int i=1;i<=tub[x];i++){
        if(!tuinit[tu2[x][i]]){
            tuinit[tu2[x][i]]=1;

            dfs2(tu2[x][i],num+1);
            tuinit[tu2[x][i]]=0;
        }
    }
    return ;
}
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    if(c>=7&&c<=11){
        for(int i=1;i<=n;i++){
            if(k[i]==1){
                continue;
            }
            tub[a[i][1]]++,tub[a[i][2]]++;
            tu[a[i][1]][tub[a[i][1]]][0]=a[i][2];
            tu[a[i][2]][tub[a[i][2]]][0]=a[i][1];
            tu[a[i][1]][tub[a[i][1]]][1]=t[i][1]+t[i][2];
            tu[a[i][2]][tub[a[i][2]]][1]=t[i][1]+t[i][2];

        }
        while(q--){
            minn=2147483647;
            cin >> sta >> las;
            dfs1(sta,0);
            cout << minn+w[sta]+w[las] << '\n';
        }

    }else{
        tt=t[1][1];
        for(int i=1;i<=n;i++){
            if(k[i]==1){
                continue;
            }
            for(int j=1;j<=k[i];j++){
                tub[j]=tub[j]+k[i]-1;
                for(int l=1,jj=0;l<=k[i];l++){
                    if(j==l){
                        continue;
                    }
                    jj++;
                    tu2[a[i][j]][jj]=a[i][l];
                }
            }
            while(q--){
                minn=2147483647;
                cin >> sta >> las;
                dfs2(sta,0);
                cout << minn*tt*2+w[sta]+w[las] << '\n';
            }
        }
    }
    return 0;
}
/*
15 3 8 20 5
1 2 3 4 5 6 7 8
4 1 1 3 1 4 1 8 1
3 1 1 2 1 5 1
3 5 1 7 1 6 1
2 4
1 8
1 7
6 3
5 4
*/
