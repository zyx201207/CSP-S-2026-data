#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int l[100001];
    int mp[100001];
    int ans[100001]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>l[i];
        mp[l[i]]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mp[l[j]]+=1;
            if(mp[l[j]]>1){
                int x;
                for(int k=1;k<=n;k++){
                    if(l[k]==l[j]){
                        x=k;
                    }
                }
                for(int k=1;k<=x;k++){
                    mp[l[k]]--;
                }
            }

        }
        for(int i=1;i<=m;i++){
            if(mp[i]==1){
                ans[mp[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}
