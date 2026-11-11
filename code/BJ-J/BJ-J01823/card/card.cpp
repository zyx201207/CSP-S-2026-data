#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
map<long long,long long> ans;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    for(long long i=1;i<=n;i++){
        map<long long,bool> mp;
        mp.clear();
        vector<long long> num;
        num.clear();
        for(long long j=i;j<=n;j++){
            if(mp[a[j]]==1){
                while(num.size()!=0&&num[num.size()-1]!=a[j]){
                    num.pop_back();
                }
            }else{
                mp[a[j]]=1;
                num.push_back(a[j]);
            }
        }
        mp.clear();
        for(long long j=0;j<num.size();j++){
            if(mp[num[j]]==0) ans[num[j]]++;
            mp[num[j]]=1;
        }
    }
    for(long long i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
