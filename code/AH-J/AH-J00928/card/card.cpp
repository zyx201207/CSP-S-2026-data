#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t[200020],a[200020],ans[200020];
signed main(){
 //   freopen("card.in","r",stdin);
  //  freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<int> ca;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(t[a[i]]==1){
            int j=ca.size();
            while(ca[j]!=a[i]){
                ca.pop_back();
                j--;
                t[j]=0;
            }
        }
        ca.push_back(a[i]);
        t[a[i]]=1;
        for(int k=0;k<ca.size();k++){
            //cout<<ca[k]<<" ";
            ans[ca[k]]++;
            cout<<ans[1]<<" ";
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
