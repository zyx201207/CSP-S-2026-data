#include<bits/stdc++.h>

using namespace std;

int c,T;
int n,d;
int lst[2000005];
int sum[2000005];
int check(int x,int s,int t){
    int now=0,cnt=0;
    if((~x)&1 && (~x)&(1<<(t-s+1))){
        return -1;
    }
    for(int i=1;i<=t-s+1;i++){
        if(x&(1<<(i-1))){
            if(now==0){
                now=i+s-1;
                continue;
            }

            if(abs(lst[i+s-1]-lst[now])>d){
                return -1;
            }
            else{
                now=i+s-1;
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>lst[i];
        }

        int ans=0;
        for(int u=1;u<=n;u++){
            for(int v=u+1;v<=n;v++){
                memset(sum,0,sizeof(sum));
                int mini=0x3f3f3f3f;
                for(int i=1;i<=(1<<(v-u+1))-1;i++){
                    int now=check(i,u,v);
                    if(now!=-1){
                        mini=min(mini,now);
                        sum[now]++;
                    }
                }
                if(sum[mini]==2){
                    cout<<u<<" "<<v<<'\n';
                    ans++;
                }
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}
