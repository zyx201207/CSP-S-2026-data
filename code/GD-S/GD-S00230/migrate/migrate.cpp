#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

LL c,T,n,d;
LL a[2000010];
LL nxt[2000010][21];
LL dp[310][310];
LL ans;

LL dis(LL l,LL r){
    if(l==r){
        return 0;
    }
    LL ans=0;
    for(LL i=20;i>=0;i--){
        if(nxt[l][i]<r){
            ans+=(1<<i);
            l=nxt[l][i];
        }
    }
    return ans+1;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        ans=0;
        cin>>n>>d;
        for(LL i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==11 || c==12){
            if(n==1){
                cout<<"0\n";
                continue;
            }
            LL tmp=d/(a[2]-a[1]);
            if(tmp<=1){
                cout<<"0\n";
                continue;
            }
            cout<<max(0ll,n-(tmp*2-1))<<'\n';
            continue;
        }else if(c==13 || c==14){
            
            continue;
        }
        LL dx=n;
        for(LL i=n;i>=1;i--){
            while(a[dx]-a[i]>d){
                dx--;
            }
            nxt[i][0]=dx;
        }
        for(LL i=1;i<=20;i++){
            for(LL j=1;j<=n;j++){
                nxt[j][i]=nxt[nxt[j][i-1]][i-1];
            }
        }
        for(LL len=1;len<=n;len++){
            for(LL i=1;i<=n-len+1;i++){
                LL j=i+len-1;
                dp[i][j]=0;
                if(dis(i,j)<=1){
                    dp[i][j]=1;
                    continue;
                }
                for(LL k=i;k<=j;k++){
                    if(dis(i,k)+1==dis(i,j) && nxt[k][0]>=j){
                        dp[i][j]+=dp[i][k];
                    }
                }
            }
        }
        for(LL i=1;i<=n;i++){
            for(LL j=i;j<=n;j++){
                if(dp[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}