#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

int a[500005];
bool vis[300005];
int ans[300005]={0};

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    memset(ans,0,sizeof(ans));
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        stack<int> s;

        s.push(a[i]);
        vis[a[i]]=true;
        for(int j=i+1;j<=n;j++){
            if(vis[a[j]]==false){
                s.push(a[j]);
                vis[a[j]]=true;
            }else{
                while(s.top()!=a[j]){
                    vis[s.top()]=false;
                    s.pop();
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(vis[j]==true){
                vis[j]=false;
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
