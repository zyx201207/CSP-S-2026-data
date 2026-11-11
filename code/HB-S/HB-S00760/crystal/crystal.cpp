#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n;
    long long m;
    cin>>n>>m;
    vector<long long> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(n==1){
        cout<<1;
        return 0;
    }
    bool check=true;
    int gc=a[1]-a[0];
    for(int i=2;i<n;++i){
        if(a[i]-a[i-1]!=gc){
            check=false;
            break;
        }
    }
    if(check){
        m=m*1.0L/gc*2;
        for(long long i=max((long long)sqrt(m)-2,0LL);i<=sqrt(m)+3;i++){
            if(i*(i+1)<=m&&(i+1)*(i+2)>m){
                cout<<min(i+1,(long long)n);
                return 0;
            }
        }
    }
    int ans=0;
    a.push_back((long long)1e18 + 9999);
    for(int i=0;i<n;++i){
        int cur=i;
        while((a[cur+1]-a[cur])*(cur-i+1)<=m){
            m-=(a[cur+1]-a[cur])*(cur-i+1),
            ++cur;
            if(cur==n)
                break;
        }
        ans=max(ans,cur-i+1);
        if(cur==n)
            break;
    }
    cout<<ans;
    return 0;
}
