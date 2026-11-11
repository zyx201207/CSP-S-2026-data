#include<cstdio>
#include<cstring>
using namespace std;

int a[500005];
int ans[300005];
int t[500005];
int loc[500005];
bool ex[500005];
int p=0;
int n,m;

void f1(int w){
    for(int i=w;i<=n;i++){
        int v=a[i];
        if(loc[v]==-1||loc[v]>p){
            t[++p]=v;
            loc[v]=p;
        }
        else{
            p=loc[v];
        }
    }
    for(int i=1;i<=p;i++){
        if(ex[t[i]]==false){
            ans[t[i]]++;
            ex[t[i]]=true;
        }
    }
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int w=1;w<=n;w++){
        memset(t,0,sizeof(t));
        memset(loc,-1,sizeof(loc));
        memset(ex,0,sizeof(ex));
        p=0;
        f1(w);
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
