#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],c[300010],l[500010],r[500010],ans[300010],p[500010],t[500010];
int lowbit(int x){return x&-x;}
void add(int x,int y){
    if(x==0){
        return;
    }
    for(;x<=n;x+=lowbit(x))t[x]=max(t[x],y);
}
int ask(int x){
    int res=0;
    for(;x;x-=lowbit(x))res=max(res,t[x]);
    return res;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i=n;i;i--){
        if(c[a[i]])r[i]=c[a[i]];
        c[a[i]]=i;
    }
    for(int i=1;i<=n;i++)c[i]=0;
    for(int i=1;i<=n;i++){
        if(c[a[i]])l[i]=c[a[i]];
        c[a[i]]=i;
    }
    //for(int i=1;i<=n;i++)printf("%d ",i);printf("\n");
    //for(int i=1;i<=n;i++)printf("%d ",a[i]);printf("\n");
    //for(int i=1;i<=n;i++)printf("%d ",r[i]);printf("\n");


    for(int i=1;i<=n;i++){
        add(n-r[i]+1,i);
        //printf("%d %d\n",a[i],ask(n-i));
        if(!r[i])ans[a[i]]+=max(0,i-ask(n-i));
    }
    for(int i=1;i<=m;i++)printf("%d ",ans[i]);
    printf("\n");
}
