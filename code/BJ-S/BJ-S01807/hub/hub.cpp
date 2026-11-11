#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=5e5+10;
long long pre[N],k,dx,x,y,len,c,t,n,m,di[10005][10005],mx=INT_MIN,mn=INT_MAX,ra;
int d[N];
bool f[N];
struct node{
    int to;
    int len;
    int next;
}a[N];
void add(int u,int v,int l){
    dx++;
    a[dx].to=v;
    a[dx].len=l;
    a[dx].next=pre[u];
    pre[u]=dx;
}
priority_queue<PII,vector<PII>,greater<PII>>heap;
void spfa(int x,int y)
{
    memset(d,0x3f,sizeof(d));
    heap.push({0,x});
    d[x]=0;
    while(!heap.empty()){
        PII h=heap.top();
        heap.pop();
        int dis=h.first,p=h.second;
        if(f[p])continue;
            f[p]=true;
        if(p==y){
                ra=dis;
            return;
        }
        for(int i=pre[p];i!=0;i=a[i].next){
            int to=a[i].to;
            if(d[to]>dis+a[i].len){
                d[to]=dis+a[i].len;
                heap.push({d[to],to});
            }
        }
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int j=1;j<=t;j++){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            cin>>x>>y;
            add(x,y,1);
            add(y,x,1);
        }
        for(int i=1;i<=n;i++){
            long long hv;
            for(int k=1;k<=n;k++){
                spfa(i,k);
                di[i][k]=ra;
                mx=max(mn,ra);
                hv=mx;
            }
            mn=min(hv,mn);
        }
        if(k==1){
            cout<<mn<<endl;
        }
        else if(k==2){
            for(long long i=1;i<n;i++){
                for(long long k=2;k<=n;k++){
                    for(int l=1;l<=n;l++){
                        spfa(i,l);
                        mn=min(ra,i);
                        spfa(l,k);
                        mn=min(ra,k);
                        mx=max(mn,mx);
                    }
                }
            }
            cout<<mx<<endl;
        }
    }
    return 0;
}

