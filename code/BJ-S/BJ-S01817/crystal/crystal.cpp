#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[5000005];
long long ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n>5000)return 0;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++){
        long long m1=m;
        vector<long long> v;
        long long cnt=1;
        for(int j=1;j<i;j++){
            v.push_back(a[i]-a[j]);
        }
        int j1=i-1;
        while(j1>0&&m1>v[j1]){
            m1-=v[j1];
            j1--;
            cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
