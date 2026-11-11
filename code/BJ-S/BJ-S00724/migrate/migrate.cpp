#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,num,cnt,sum,x[2000010];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        cnt=sum=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            num=x[i]-x[i-1];
        }
        if(d>=x[n]-x[1]||num>=d){
            cout<<0<<"\n";
            continue;
        }
        while(sum<d){
            sum+=num;
            cnt++;
        }
        if(d%num){
            cnt--;
        }
        cnt+=cnt-1;
        cout<<n-cnt<<"\n";
    }
    return 0;
}
