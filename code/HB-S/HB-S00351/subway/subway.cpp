#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
int c,n,m,d,q;
long long w[500010],d1[500010],d2[21],l[500010][21],l2[21][500010];
int v[500010][21],v2[21][500010],len[500010],len2[21];
struct node{
    int d,f;
    long long len;
};
long long get(int b,int e){
    fill(d1,d1+500001,INT_MAX);
    for(int i=1;i<=n;i++)d2[i]=INT_MAX;
    queue<node>q;
    q.push({b,0,0});
    while(q.size()){
        node k=q.front();
        q.pop();
        int j;
        long long dis;
        if(k.f==0){
            d1[k.d]=k.len;
            for(int i=1;i<=len[k.d];i++){
                j=v[k.d][i];dis=l[k.d][i];
                if(d2[j]>k.len+dis)q.push({j,1,k.len+dis});
            }
        }else{
            d2[k.d]=k.len;
            for(int i=1;i<=len2[k.d];i++){
                j=v2[k.d][i];dis=l2[k.d][i];
                if(d1[j]>k.len+dis)q.push({j,0,k.len+dis});
            }
        }
    }
    return d1[e];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int k,kl1,lll,rrr;
    long long kl2;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d%lld",&kl1,&kl2);
            len[kl1]++;len2[i]++;
            v[kl1][len[kl1]]=i;
            v2[i][len2[i]]=kl1;
            l[kl1][len[kl1]]=l2[i][len2[i]]=kl2;
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&lll,&rrr);
        printf("%lld\n",get(lll,rrr)+w[lll]+w[rrr]);
    }
    return 0;
}