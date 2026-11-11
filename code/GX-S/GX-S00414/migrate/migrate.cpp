#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,x[2000005],ans[2000005],l[2000006],r[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        vector<int>l,r;
        ans[1]=0;
        for(int i=1;i<=n;i++)ans[i]=ans[i-1]+(x[i]-x[i-1]);
        int cnt=0;
        l.push_back(1);
        r.push_back(1);
        while(r[cnt]+1<=n){
            while(ans[r[cnt]+1]-ans[l[cnt]]<=d&&r[cnt]+1<=n)r[cnt]++;
            if(r[cnt]==n)break;
            cnt++;
            l[cnt]=l[cnt-1]+1;
            r[cnt]=r[cnt-1];
        }
        //for(int i=0;i<=cnt;i++)cout<<l[i]<<" "<<r[i]<<"\n";
        //cout<<"\n";
        int sum=0,ltot=0,rtot=0;
        while(rtot+1<=cnt){
            if(r[ltot]-l[rtot]>1)rtot++;
            else if(r[ltot]-l[rtot]<1)ltot++;
            else if(r[ltot]-l[rtot]==1){
                while(r[ltot]-l[rtot]==1){
                    sum++;
                    ltot++;
                }
                rtot++;
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}
