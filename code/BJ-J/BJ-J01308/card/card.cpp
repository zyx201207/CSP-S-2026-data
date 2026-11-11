#include<cstdio>
#include<cstring>
using namespace std;
const int N=5e5+1;
const int M=3e5+1;
int a[N],t[M],n,m,ans[M],num[M];
void delet(int b,int e){
    for(int i=b;i<=e;i++){
        t[a[i]]=-1;
        if(num[a[i]]){
            ans[a[i]]--;
            num[a[i]]--;
        }
    }
}
void solve(int x){
    for(int i=x;i<=n;i++){
        if(t[a[i]]!=-1){
            delet(t[a[i]]+1,i-1);
            t[a[i]]=i;
        }else{
            t[a[i]]=i;
            ans[a[i]]++;
            num[a[i]]++;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        memset(t,-1,sizeof(t));
        memset(num,0,sizeof(num));
        solve(i);
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}