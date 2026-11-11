#include<bits/stdc++.h>
#define LL long long
#define Uint unsigned int
#define ULL unsigned LL
#define pii pair<int,int>
#define pLL pair<LL,LL>
#define fr first
#define se second
#define pb push_back
#define isr insert
#define _i128 __int128
using namespace std;
const int N = 5e5+5;
struct node{int x,ed,val,to;}p[N];
int n,m,a[N],ans[N];
int read(){
    int su=0,pp=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')pp=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){su=su*10+ch-'0';ch=getchar();}
    return su*pp;
}
bool cmp(node d1,node d2){return d1.ed<d2.ed;}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=m;i++)ans[i]=0,p[i].x=i;
    for(int i=1;i<=n;i++){
        a[i]=read();
        p[a[i]].ed=i,p[a[i]].val++;
    }
    for(int i=1;i<=m;i++){
        int id=p[i].ed+1;
        p[i].to=a[id];
    }
    sort(p+1,p+m+1,cmp);
    for(int i=1;i<=m;i++){
        ans[p[i].x]+=p[i].val;
        ans[p[i].to]+=ans[p[i].x];
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
/*

1h ak
ÏÖÔÚÊÇ9:35

*/
