#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long ma=LLONG_MIN;
bool flag[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    //solve how many bits
    int bits=0;
    if(ma==0) bits=1;
    else{while(ma>0){
        ma>>=1;
        bits++;
    }}
    //bits end
    //jinri silu:pai 0
    long long ans=0;
    for(int i=bits-1;i>=0;i--){
        int tmp=0;
        //find 0
        vector<int> tf;
        for(int j=1;j<=n;j++){
            if(flag[j]) continue;
            if(((1<<i)&a[j])==0){
                tf.push_back(j);
            }else{
                tmp++;
            }
        }
        if(tmp>=m){
            ans+=(1<<i);
            for(auto u:tf){
                flag[u]=true;
            }
        }
        //ci chu else ke neng mei you cao zuo miao
    }
    cout<<ans<<endl;
}
