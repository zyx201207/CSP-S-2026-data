#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans;/*,b[N*10],xn*/
/*long long ret;
long long one(int x){
    long long res=0;
    if(x==0)return 0;
    while(x){
        res+=x%2;
        x/=2;
    }
    return res;
}
bool ke(int x){
    long long idx=0;
    while(x){
        idx++;
        int yu=x%2;
        if(!b[idx]&&yu)return
    }
}*/
bool cmp1(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cmp1);
    /*int x=a[1],id=0;
    while(x){
        int yu=x%2;
        if(yu==0)b[++id]=yu;
        ret++;
        x/=2;
    }*/
    ans=a[1];
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    printf("%d",ans);
    return 0;
}
