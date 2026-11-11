#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m,a[N],w=29;
bool cmp(int x,int y){
    return ((x>>w)&1)>((y>>w)&1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    for(w = 29;w>=0;w--){
        sort(a+1,a+n+1,cmp);
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            if((a[i]>>w)&1)cnt++;
        }
        if(cnt >= m)n=cnt;
    }
    int ans = (1<<30)-1;
    for(int i = 1;i<=m;i++)ans&=a[i];
    printf("%d\n",ans);
}