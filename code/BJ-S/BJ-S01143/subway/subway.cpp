#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000005];
vector<int> vt[2000005];
int cnt;
void dfs(int cur,int x,int y,int len){
    if(cur>len){
        cnt++;
        return;
    }
    for(auto i:vt[x]){
        if(i>y)break;
        dfs(cur+1,i,y,len);
    }
}
bool chk(int x,int y){
    if(x==y-1)return false;
    int l=1,r=y-x+1;
    int ans=1;
    while(l<=r){
        int m=(l+r)/2;
        dfs(1,x,y,m);
        if(cnt>0){
            ans=m;
            r=m-1;
        }else l=m+1;
        cnt=0;
    }
    dfs(1,x,y,ans);
    bool flag;
    if(cnt==2)flag=true;
    else flag=false;
    cnt=0;
    return flag;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        ll n,d;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        int last=1;
        for(int i=2;i<=n;i++){
            for(int j=last;j<i;j++){
                if(a[i]-a[j]>d)last++;
                else vt[j].push_back(i);
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=n;j>i;j--){
                if(chk(i,j)){
                    ans++;
                }
            }
        }
        printf("%lld\n",ans);
        for(int i=1;i<=n;i++)while(vt[i].size())vt[i].pop_back();
    }
    return 0;
}