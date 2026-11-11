#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,num,ans,limit,m;
struct node{
    int s[35];
}a[N];
bool cmp(node a,node b){
    return a.s[limit]>b.s[limit];
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        for(int j=0;j<30;j++) a[i].s[j]=(num>>j)&1;
    }
    for(int i=29;i>=0;i--){
        limit=i;
        sort(a+1,a+n+1,cmp);
        int cnt=0;
        for(int j=1;j<=n;j++) cnt+=a[j].s[i];
        if(cnt>=m) n=cnt,ans+=(1<<i);
    }
    printf("%d\n",ans);
    return 0;
}
