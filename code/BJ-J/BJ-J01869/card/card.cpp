#include<bits/stdc++.h>
using namespace std;

int a[500010];

map<int,int> mp;

int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int x=1;x<=m;x++){
        vector<int> v;
        int bac=0;
        int ans=0;
        mp.clear();
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(mp.find(a[j])!=mp.end()){
                    bac=mp[a[j]];
                }
                else{
                    if(v.size()==bac){
                        v.push_back(a[j]);
                        bac++;
                        mp[a[j]]=bac;
                    }
                    else{
                        v[bac]=a[j];
                        mp[a[j]]=bac;
                        bac++;
                    }
                }
            }
            for(int j=0;j<=bac;j++){
                //cout<<v[j]<<endl;
                if(v[j]==x){
                    ans++;
                }
            }
        }
        cout<<ans<<" ";
    }

    return 0;
}
