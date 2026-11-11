#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> num;
    long long ans=0;
    for(long long i=0;i<n;i++){
        long long a;
        cin>>a;
        num.push_back(a);
    }
    for(long long i=n-1;i>=0;i--){
        vector<long long> c;
        long long cs=0;
        long long sum=0;
        for(long long j=0;j<i;j++){
            long long p=num[i]-num[j];
            if(p<=m){
                c.push_back(p);
            }
        }
        sort(c.begin(),c.end());
        for(int j=0;j<c.size();j++){
            sum+=c[j];
            if(sum>m){
                break;
            }
            cs++;
        }
        cs++;
        ans=max(ans,cs);
    }
    cout<<ans<<endl;
    return 0;
}
