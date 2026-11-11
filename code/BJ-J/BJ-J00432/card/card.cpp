#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],aa[55000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m<=2){
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(mp[a[i]]==0){
                    mp[a[i]]++;
                }


            }
            for(int j=1;j<=m;j++){
                if(mp[j]==1)aa[j]++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<aa[i]<<" ";
        }
    }
    return 0;
}
