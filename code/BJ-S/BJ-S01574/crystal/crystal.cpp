#include<bits/stdc++.h>
using namespace std;
long long ab[500005];
long long ac[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,maxx=-1e9;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ab[i];
    }
    for(int i=1;i<=n;i++){
        long long mm=m,cnt=0;
        memset(ac,0,sizeof(ac));
        priority_queue<long long,vector<long long>,greater<long long>> dp;
        for(int j=1;j<=n;j++){
            if(ab[i]>=ab[j]){
               ac[j]=abs(ab[i]-ab[j]);
                dp.push(ac[j]);
            }
        }
        while(!dp.empty() && mm>=dp.top()){
            mm-=dp.top();
            dp.pop();
            cnt++;
        }
        maxx=max(maxx,cnt);
    }
    cout<<maxx;
    return 0;
}
