#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
//vector<int> b[500005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vector<int> x;
        vector<int> y;
        for(int j=i;j<=n;j++){
            y.clear();
            for(int q:x){
                if(q==a[j]) break;
                y.push_back(q);
            }
            x=y;
            x.push_back(a[j]);
        }
        for(int q:x){
            ans[q]++;
        }
    }
    /*for(int i=n;i>=1;i--){
        if(!b[i-1].empty()){
            int j=-1;
            for(j=b[i-1].size();j>=0;j--){
                if(b[i-1][j]==a[i]) break;
                b[i].push_back(b[i][j]);
                ans[j]++;
            }
            for(int q=0;q<j;q++){
                b[i].push_back(b[i-1][q]);
                ans[b[i-1][q]]++;
            }
        }
        ans[a[i]]++;
        b[i].push_back(a[i]);
    }*/
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
