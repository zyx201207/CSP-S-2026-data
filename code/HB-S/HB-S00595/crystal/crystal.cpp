#include<bits/stdc++.h>
using namespace std;
long long a[500001];
long long n,m,num,cnt,ans;
queue<long long>b;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        num+=cnt*(a[i]-a[i-1]);
        while(num>m){
            num-=a[i]-b.front();
            b.pop();
            cnt--;
        }
        b.push(a[i]);
        cnt++;
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}
