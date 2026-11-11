#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],cnt[300010],f[300010];
vector<long long>v;
map<long long,long long>mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(mp.count(a[j])==1){
                for(int k=j;k<mp.size();k++){
                    mp[a[k]]=0;
                }
            }
            v.push_back(a[j]);
            mp[a[j]]++;
        }
        for(int j=0;j<v.size();j++){
            if(mp[v[j]]!=0&&v[j]>=1&&v[j]<=m&&f[v[j]]==0){
                cnt[v[j]]++;
                f[v[j]]=1;
            }
        }
        memset(f,0,sizeof(f));
        v.clear();
        mp.clear();
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}


