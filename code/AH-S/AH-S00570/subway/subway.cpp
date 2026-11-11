#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
struct node{
    int z[5000],c=0,t[5000]={0};
}a[5000];
struct nd{
    long long o,u;
};
long long bfs(int g,int b)
{
    nd r;
    long long ans=10000000000000000;
    r.o=g,r.u=0;
    queue<nd> q;
    q.push(r);
    while(1)
    {
        if(q.size()==0)break;
        nd R=q.front();
        q.pop();
        if(R.u>ans)continue;
        int x=R.o;
        for(int i=1;i<=a[x].c;i++)
        {
            nd ram=R;
            ram.o=a[x].z[i];
            ram.u=ram.u+a[x].t[ram.o];
            if(ram.o==b)
                ans=min(ans,ram.u);
            if(ram.o!=b&&ram.u<ans)
                q.push(ram);
        }
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    for(int i=1,k,aa[512],t[512];i<=n;i++)
    {
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
            scanf("%d%d",&aa[j],&t[j]);
        for(int j=1;j<=k;j++)
            for(int l=j+1;l<=k;l++)
            {
                int x=aa[j],y=aa[l];
                if(a[x].t[y]!=0)
                    a[x].t[y]=min(a[x].t[y],t[j]+t[l]),a[y].t[x]=a[x].t[y];
                else if(a[x].t[y]==0)
                    a[x].c++,a[y].c++,a[x].z[a[x].c]=y,a[y].z[a[y].c]=x,a[x].t[y]=t[j]+t[l],a[y].t[x]=t[j]+t[l];
            }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        unsigned long long ans=0;
        ans=ans+w[x]+w[y];
        cout<<bfs(x,y)+ans<<endl;
    }
    return 0;
}
