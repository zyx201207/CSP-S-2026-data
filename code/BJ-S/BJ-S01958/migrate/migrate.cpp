#include<bits/stdc++.h>
using namespace std;
int n,d,a[100010],b[100010],s[100010],mi=INT_MAX,ans,ra;
bool fl=0,bs=0;
void dfs(int x,int p,int cnt,int tar){ //x wei xia biao,p wei dang qian ju li,xnt wei shuliang
    if(p==s[tar]&&x==tar){
        mi=min(cnt,mi);
        if(fl&&mi==cnt) ans++;
        return ;
    }
    if(p>mi) return ;
    for(int i=x+1;i<=n;i++){
        if(s[i]<=p+d){
            dfs(i,s[i],cnt+1,tar);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c122,T;
    cin>>c122>>T;
    while(T--){
        cin>>n>>d;
        memset(a,0,sizeof(a));
        ans=0;
        mi=INT_MAX;
        fl=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=abs(a[i]-a[i-1]);
            s[i]=b[i-1]+b[i];
        }
        if(a[n]-a[1]<=d) {
            cout<<0<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;i+j<=n;j++){
                if(a[i+j]-a[i]<d) {
                    continue;
                }
                dfs(i,0,0,i+j);
                fl=1;
                dfs(i,0,0,i+j);
                if(ans>1) ra++;
                ans=0;
                mi=INT_MAX;
            }
        }
        cout<<ra<<"\n";
        ra=0;
    }
    return 0;
}
