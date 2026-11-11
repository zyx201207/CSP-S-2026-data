#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 200005;
int lis[N];
int len,lose;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d",&n ,&m);
    for(int i=0;i<=n;i++){
        scanf("%d",&lis[i]);
         int ma = max[ma,lis[i]];
    }
    int l=0;
    for(int i = ma;i>0;i>>=1){
        l++;
    }
    lose=(1<<l)-1+(1<<l);
    len = 1;
    for(int i=l;i>=1;i--){
        sort(lis+len,lis+1+n,cmp);

    }

    return 0;
}
