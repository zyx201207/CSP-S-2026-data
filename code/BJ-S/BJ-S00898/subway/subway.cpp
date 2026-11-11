#include<bits/stdc++.h>
using namespace std;
int n,m,q,ans=-1,x,y,k;//line,point,question
int w[505];
vector<int> a[505],t[505];
bool vis[1005];
void dfs(int tim,int sta,int line){
    if(sta==y){
        ans=max(ans,tim);
        return;
    }
    if(vis[sta]) return;
    vis[sta]=1;
    for(int i=1;i<=n;i++){
        if(line==i){
            for(int j=1;j<=k;j++){
                dfs(tim,a[i][j],line);
            }
        }
        else if(find(a[i].begin(),a[i].end(),sta)!=a[i].end()){
            for(int j=1;j<=k;j++){
                dfs(tim+t[i][j]+t[line][sta],a[i][j],i);
            }
        }
    }
    vis[sta]=0;
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>n>>m>>q>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
    for(int i=1;i<=q;i++){
        ans=-1;
        cin>>x>>y;
        dfs(w[x]+w[y],x,0);
    }
    return 0;
}
/*
#include<bits/stdc++.h>
//#include<windows.h>
using namespace std;
int main(){
    //froepen("game.in","r",stdin);
    srand(time(NULL));
    long double a=100,b=100,c=100;
    bool x=1,y=1,z=1;
    while(x||y||z){
        //system("cls");
        if(x){
            a-=rand()%3>0?a*(rand()%5)/100:-a*(rand()%3)/100;
            cout<<a<<' ';
        }
        if(y){
            b-=rand()%3>0?b*(rand()%10)/100:-b*(rand()%10)/100;
            cout<<b<<' ';
        }
        if(z){
            c-=rand()%3>0?c*(rand()%15)/100:-b*(rand()%15)/100;
            cout<<c<<' ';
        }
        int op;
        cin>>op;
        switch(op){
            case 1:
            if(!x)break;
            if((rand()%100)<a){
                cout<<"Over!\n";
                return 0;
            }
            x=0;
            break;
            case 2:
            if(!y)break;
            if((rand()%100)<b){
                cout<<"Over!\n";
                return 0;
            }
            y=0;
            break;
            case 3:
            if(!z)break;
            if((rand()%100)<c){
                cout<<"Over!\n";
                return 0;
            }
            z=0;
            break;
        }
    }
    cout<<"win!\nRP++\n";

    return 0;
}
*/