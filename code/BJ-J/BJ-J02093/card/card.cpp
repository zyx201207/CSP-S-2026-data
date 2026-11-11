#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 500005
#define M 300005

inline LL read(){
    char ch=getchar();
    LL p=0;
    int w=1;
    while(ch<'0'||'9'<ch){
        if(ch=='-')w=-w;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        p=(p<<3)+(p<<1)+(ch^48);
        ch=getchar();
    }
    return p*w;
}
inline void write(LL x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline int readI(){
    char ch=getchar();
    int p=0;
    int w=1;
    while(ch<'0'||'9'<ch){
        if(ch=='-')w=-w;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        p=(p<<3)+(p<<1)+(ch^48);
        ch=getchar();
    }
    return p*w;
}
inline void writeI(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}


struct node{
    int num,val;
}lst[M];
bool cmp(node x,node y){
    return x.val<y.val;
}
int a[N],cnt[M];
int ans[M];
vector<int>edge[M];

void dfs(int pos){
    ans[pos]=cnt[pos];
    for(int i=0;i<edge[pos].size();i++){
        int v=edge[pos][i];
        dfs(v);
        ans[pos]+=ans[v];
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n=readI(),m=readI();
    for(int i=1;i<=n;i++){
        a[i]=readI();
        lst[a[i]]={a[i],i};
        cnt[a[i]]++;
    }

    sort(lst+1,lst+m+1,cmp);

    for(int i=1;i<m;i++){
        edge[a[lst[i].val+1]].push_back(lst[i].num);
    }

    dfs(lst[m].num);

    for(int i=1;i<=m;i++){
        write(ans[i]);
        if(i!=m)putchar(' ');
        else putchar('\n');
    }
    return 0;
}
