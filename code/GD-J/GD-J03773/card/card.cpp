#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int fa[310000];
int n,m;
int a[510000];
long long cnt[310000];
int deg[310000];

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    a[n+1]=0;
    for(int i=1;i<=n;i++) {
        cnt[a[i]]++;
        fa[a[i]]=a[i+1];
    }
    for(int i=1;i<=m;i++) deg[fa[i]]++;
    queue<int> q;
    for(int i=1;i<=m;i++) {
        if(deg[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        cnt[fa[x]]+=cnt[x];
        deg[fa[x]]--;
        if(deg[fa[x]]==0) q.push(fa[x]);
    }
    for(int i=1;i<=m;i++) {
        printf("%lld ",cnt[i]);
    }
    printf("\n");
}