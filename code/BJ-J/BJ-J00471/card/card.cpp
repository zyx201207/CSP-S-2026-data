#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],ans[maxn];
bool p;
vector<int>crd;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i-1]>a[i])p=1;
    }
    if(!p){
        for(int i=1;i<=n;i++){
            ans[a[i]]=max(ans[a[i]],i);
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            bool pd=0;
            for(auto v:crd){
                if(v==a[j]){
                    pd=1;
                }
            }
            if(!pd)crd.push_back(a[j]);
            else{
                while(crd[crd.size()-1]!=a[j]){
                    crd.pop_back();
                }
            }
        }
        while(!crd.empty()){
            ans[crd[crd.size()-1]]++;
            crd.pop_back();
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}