#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int st,dis;
int cnt[5010][5010];
int c,t,n,d;
int a[2000010];
int mn[5010][5010];
void f(int x){
    if(mn[st][x]>dis){
        mn[st][x]=dis;
        cnt[st][x]=0;
    }
    cnt[st][x]++;
    for(int i=x+1;i<=n;i++){
        if(a[i]-a[x]<=d){
            dis++;
            f(i);
            dis--;
        }else{
            return;
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        memset(mn,0x3f,sizeof(mn));
        cin>>n>>d;
        memset(cnt,0,sizeof(cnt));
        int dif=0;
        bool flag=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>2&&dif!=a[i]-a[i-1]){
                flag=0;
            }
            dif=a[i]-a[i-1];
        }
        if(flag||c==11||c==12){
            int x=d/(a[2]-a[1]);
            if(x<=1){
                cout<<0<<endl;
                continue;
            }
            cout<<max(0LL,n-2*x+1)<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            st=i;
            dis=0;
            f(i);
        }
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(cnt[i][j]==2){
                    res++;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}