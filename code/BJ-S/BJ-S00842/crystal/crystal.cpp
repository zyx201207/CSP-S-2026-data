#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    bool pd = 1;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long d1 = a[n] - a[n-1];
    for(int i = 2;i < n;i++){
        if(a[i+1] - a[i] != d1) pd = 0;
    }
    long long ans = 1;
    long long sum = 0;
    long long maxx = 0;
    if(pd){
        for(int i = 1;i <= n;i++){
            sum += d1*i;
            if(sum > m) break;
            else ans++;
        }
        cout<<ans<<endl;
        return 0;
    }
    else{
        for(int i = 2;i <= n;i++){
            sum = 0;
            ans = 0;
            for(int j = i;j >= 1;j--){
                sum += a[i]-a[j];
                if(sum > m) break;
                else ans++;
                //cout<<sum<<" "<<ans;
            }
            maxx  = max(maxx,ans);
            //cout<<sum<<" "<<ans<<" ";
        }
    }
    cout<<maxx<<endl;
    return 0;
}
