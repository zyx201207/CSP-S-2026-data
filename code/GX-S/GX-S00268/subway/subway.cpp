#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
vector<pair<int,int> > p[500003];
int w[500003];
int dis[503][503];
int du(){
    int f=1,d=0;
    char a=getchar();
    while(a<'0' || a>'9'){
        if(a=='-'){
            f=-1;
        }
        a=getchar();
    }
    while('0'<=a && a<='9'){
        d=d*10+a-'0';
        a=getchar();
    }
    return d*f;
}
signed main(){
    int i,j,l,c,k,d,q;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //cin>>c>>n>>m>>d>>q;
    c=du();
    n=du();
    m=du();
    d=du();
    q=du();
    for(i=1;i<=m;i++){
       // cin>>w[i];
        w[i]=du();
    }
    for(i=1;i<=n;i++){
        int num1;
        //cin>>num1;
        num1=du();
        for(j=1;j<=num1;j++){
            int x,y;
           // cin>>x>>y;
            x=du();
            y=du();
            p[x].push_back(make_pair(i,y));
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i!=j){
                dis[i][j]=40000000000;
            }
            else{
                dis[i][j]=0;
            }
        }
    }
    for(i=1;i<=m;i++){
        for(j=(int)(0);j<p[i].size();j++){
            for(l=j+(int)(1);l<p[i].size();l++){
                pair<int,int> u1=p[i][j],u2=p[i][l];
                dis[u1.first][u2.first]=u1.second+u2.second;
                dis[u2.first][u1.first]=u1.second+u2.second;
            }
        }
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    for(i=1;i<=q;i++){
        int x,y,ans1=0,s=0;
        cin>>x>>y;
        for(j=0;j<p[x].size();j++){
            for(l=0;l<p[y].size();l++){
                pair<int,int> u1=p[x][j],u2=p[y][l];
                s=dis[u1.first][u2.first]+u1.second+u2.second;
               // cout<<"<"<<s<<","<<u1.first<<","<<u2.first<<">"<<endl;
                if(ans1==0){
                    ans1=s;
                }
                else{
                    ans1=min(ans1,s);
                }
            }
        }
       // cout<<"("<<ans1<<")";
        cout<<ans1+w[x]+w[y]<<endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

 * */

