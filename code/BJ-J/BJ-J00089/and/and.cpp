#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5+10;
const ll maxm=32;
ll n,m,cnt[maxm],nxt=-1,ans;
int binnum[maxn][maxm];
queue <ll> que;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++){
        ll num;
        scanf("%lld",&num);
        //cout<<num<<endl;
        for(ll j=0;j<=30&&num>0;j++,num/=2){
            binnum[i][j]=num%2;
            cnt[j]+=num%2;
            if(cnt[j]>=m)
                nxt=max(nxt,j);
        }
        que.push(i);
        //cout<<i<<endl;
    }
    //cout<<24<<endl;
    while(nxt>-1){
        //cout<<nxt<<endl;
        ans+=(1<<nxt);
        ll head=0;
        memset(cnt,0,sizeof(cnt));
        ll _nxt=-1;
        while(que.front()!=head&&!que.empty()){
            ll now=que.front();que.pop();
            if(binnum[now][nxt]==1){
                que.push(now);
                if(head==0)
                    head=now;
                for(ll i=0;i<nxt;i++){
                    cnt[i]+=binnum[now][i];
                    if(cnt[i]>=m)
                        _nxt=max(_nxt,i);
                }
            }
        }
        nxt=_nxt;
    }
    printf("%lld",ans);
    return 0;
}
