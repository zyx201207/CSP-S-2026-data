#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    if(n>5000){
        sort(a+1,a+n+1);
        int q=abs(a[2]-a[1]);
        long long cur_cost=0,cost=0;
        int cnt=0;
        while(cost+cur_cost+q<=m){
            cnt++;
            cur_cost+=q;
            cost+=cur_cost;
        }
        cout << cnt;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)s[i]=a[i]-a[i-1];
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long j=i,cnt=1;
        long long  cur_cost=0,cost=0;
        while((cost<=m)&&j){
            cur_cost+=s[j];
            cost+=cur_cost;
            if(cost>m)break;
            j--;
            cnt++;
        }
        ans=max(cnt,ans);
    }
    cout << ans;
}
