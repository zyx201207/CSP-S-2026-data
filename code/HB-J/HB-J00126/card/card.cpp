#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
long long tong[1000005];
vector<long long> vec;
long long f(long long n){
    for(long long i=0;i<vec.size();++i){
        if(vec[i]==n) return i;
    }
    return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;cin>>n>>m;
    for(long long i=1;i<=n;++i) cin>>a[i];
    for(long long i=1;i<=n;++i){
        for(long long j=i;j<=n;++j){
            long long k=f(a[j]);
            if(k==-1){
                vec.push_back(a[j]);
            }
            else{
                while(!vec.empty()&&vec.size()-1>k){
                    vec.pop_back();
                }
            }
        }
        if(!vec.empty()){
            for(long long h:vec) ++tong[h];
        }
        vec.clear();
    }
    for(long long i=1;i<=m;++i) cout<<tong[i]<<" ";
    return 0;
}
