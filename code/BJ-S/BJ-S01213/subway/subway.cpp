#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=0;
int w[500005];
int k[505];
int a[505][2005];
int t[505][2005];
int x[100005];
int y[100005];
vector <int> sta[100005];
vector <int> line[100005];
void dfs(int now,int sum,int last,int st,int bef,int bf2,int mi){
    if(now==last){
        sum=sum+t[bef][now];//
        ans=max(ans,sum);
        sum=sum-t[bef][now];
        return;
    }
    vector <int> :: iterator it;
    for(it=sta[now].begin();it!=sta[now].end();it++){
        int temp=*it;
        if(st==1){
            sum=sum+t[temp][now];//
            st=0;
            bf2=temp;
        }
        vector <int> :: iterator ti;
        for(ti=line[temp].begin();ti!=sta[temp].end();ti++){
            if(st==1){
                sum=sum+t[temp][now];//
                st=0;
            }
            int pmet=*ti;
            if(pmet!=now){
                sum=sum+t[temp][now]+t[temp][pmet];
                dfs(pmet,sum,last,st,temp,bf2,mi);
                sum=sum-t[temp][now]+t[temp][pmet];
                if(mi==1){
                    sum=sum-t[bf2][now];
                    mi=0;
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=2*k[i]+1;j++){
            scanf("%d",&a[i][j]);
            sta[j].push_back(i);
            line[i].push_back(j);
            //a[i].push_back()
            scanf("%d",&t[i][j]);
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%d",&x[i]);
        scanf("%d",&y[i]);
    }



    for(int i=1;i<=q;i++){
        int sum=0;
        sum=sum+w[x[i]]+w[y[i]];
        dfs(x[i],sum,y[i],1,0,0,1);
        printf("%d\n",ans);
        ans=0;
    }
    return 0;
}
