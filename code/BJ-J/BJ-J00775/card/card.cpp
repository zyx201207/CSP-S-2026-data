#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int pos[300010];
map<int,int> mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        mp.clear();
        for(int j=i;j<=n;j++){
            if(mp.find(a[j])!=mp.end()) mp.clear();
            mp[a[j]]++;
        }

        for(int j=1;j<=mp.size();j++){
            if(mp[j]) pos[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<pos[i]<<" ";
    }
    return 0;
}
