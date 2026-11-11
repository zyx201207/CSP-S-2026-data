#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,s[2000010],rsiz[2000010],lsiz[2000010],rf[2000010],lf[2000010],dis[5010],num[5010];
queue<int> qu;
struct bit{
    int tree[5010];
    int lowbit(int x){
        return x&(-x);
    }
    void update(int g,int x){
        for(int i=g;i<=n;i+=lowbit(i)){
            tree[i]+=x;
        }
    }
    int query(int g){
        int res=0;
        for(int i=g;i>=1;i-=lowbit(i)){
            res+=tree[i];
        }
        return res;
    }
    void clear(){
        for(int i=1;i<=n;i++){
            tree[i]=0;
        }
    }
}tr;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld %lld",&c,&t);
    while(t--){
        scanf("%lld %lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&s[i]);
        }
        if(c>10){
            for(int i=1;i<=n;i++){
                rf[i]=lf[i]=0;
                lsiz[i]=rsiz[i]=1;
            }
            if(n<=3){
                printf("0\n");
                continue;
            }
            int ans=0;
            int pos=n,ppos=n;
            for(int i=n;i>1;i--){
                while(s[pos]>s[i]+d){
                    pos--;
                }
                while(s[ppos]>s[i-1]+d){
                    ppos--;
                }
                if(pos==i||s[pos]<=s[i-1]+d){
                    continue;
                }
                rsiz[i]+=rsiz[pos];
                rf[i]=pos-max(ppos,i)-1;
            }
            pos=ppos=1;
            for(int i=1;i<n;i++){
                while(s[pos]<s[i]-d){
                    pos++;
                }
                while(s[ppos]<s[i+1]-d){
                    ppos++;
                }
                if(pos==i||s[pos]>=s[i+1]-d){
                    continue;
                }
                lsiz[i]+=lsiz[pos];
                lf[i]=min(ppos,i)-pos-1;
            }
            int ll=0,lr=0,rl=0,rr=0;
            s[0]=-4e18;
            s[n+1]=4e18;
            for(int i=2;i+2<=n;i++){
                while(s[ll]<s[i+1]-d){
                    ll++;
                }
                while(s[lr]<s[i+2]-d){
                    lr++;
                }
                while(rl<n&&s[rl+1]<=s[i-1]+d){
                    rl++;
                }
                while(rr<n&&s[rr+1]<=s[i]+d){
                    rr++;
                }
                if(ll<lr&&rl<rr&&lr<=i&&rl>=i+1){
                    //printf("[%lld,%lld)(%lld,%lld] %lld %lld\n",ll,lr,rl,rr,(lr-ll-1+lsiz[ll]+lf[ll]),(rr-rl-1+rsiz[rr]+rf[rr]));
                    ans+=(lr-ll-1+lsiz[ll]+lf[ll])*(rr-rl-1+rsiz[rr]+rf[rr]);
                }
            }
            printf("%lld\n",ans);
        }
        else{
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i;j<=n;j++){
                    dis[j]=4e18;
                }
                tr.clear();
                tr.update(i,1);
                tr.update(i+1,-1);
                dis[i]=0;
                qu.push(i);
                int maxn=i;
                while(!qu.empty()){
                    int qtop=qu.front();
                    qu.pop();
                    if(qtop>=i){
                        for(int j=maxn+1;j<=n&&s[j]<=s[qtop]+d;j++){
                            dis[j]=dis[qtop]+1;
                            qu.push(j);
                            maxn=j;
                        }
                        int pos=lower_bound(dis+i,dis+n+1,dis[qtop]+1)-dis,nn=tr.query(qtop);
                        tr.update(pos,nn);
                        if(maxn<n){
                            tr.update(maxn+1,-nn);
                        }
                        //printf("%lld a[%lld,%lld] += %lld\n",qtop,pos,maxn,nn);
                    }
                }
                for(int j=1;j<=n;j++){
                    if(tr.query(j)==2){
                        //printf("i %lld j %lld\n",i,j);
                        ans++;
                    }
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
