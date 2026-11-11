#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    // freopen("crystal.in","r",stdin);
    // freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    long long m;
    cin>>n>>m;
    vector<long long> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    int ans=0;
    for(int i=n;i>=1;i--){
        long long num=m;
        int cnt=1;
        for(int j=i-1;j>=1;j--){
            if(a[i]-a[j]<=num){
                num-=(a[i]-a[j]);
                cnt++;
            }
            if(num<=0){
                break;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}