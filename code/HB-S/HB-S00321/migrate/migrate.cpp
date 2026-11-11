#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[2000005],d;
int check(int a,int b){
    if(a+1==b)return 1;
    int cnt=0;
    if(x[b]-x[a]<=d){
        return 1;
    }
    int mi=0,now=a;
    while(now<=b){
        for(int i=now+1;i<=b;i++){
            if(x[i]-x[now]<=d){
                if(i==b){
                    mi++;break;
                }
            }
            else{
                if(now+1==i){
                    return -1;
                }
                now=i-1;
                break;
            }
        }
    }
    for(int i=a+1;i<b;i++){
        if(check(a,i)+check(i,b)==mi)cnt++;
    }
    return cnt;
}
int dp1[505],dp2[505];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c==11||c==12){
            int cha=x[2]-x[1];
            continue;
        }
        if(c==13||c==14){
            continue;
        }
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(check(j,i)==1){
                    dp1[i]+=dp1[j]+1;
                    dp2[i]+=dp2[j];
                }
                else if(check(j,i)==2){
                    dp2[i]+=dp1[j]+1;
                }
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=dp2[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
