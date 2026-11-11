#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int k[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int q=1;
    while(q<=n){
        map<int,int> mp;
        for(int i=1;i<=m;i++){
            mp[i]=0;
        }
        for(int i=q;i<=n;i++){
            if(!mp[a[i]]){
                mp[a[i]]=i;
            }else{
                for(int j=mp[a[i]];j<i;j++){
                    mp[a[j]]=0;
                }
                mp[a[i]]=i;
            }
        }
        int tot=0;
        for(int i=1;i<=m;i++){
            if(mp[i]){
                k[i]++;
            }
        }
        q++;
    }
    for(int i=1;i<=m;i++){
        cout<<k[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
