#include<bits/stdc++.h>
using namespace std;
bool find(vector<int>f,int n){
    for(auto i:f){
        if(i==n)return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","r",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1),dp(m+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vector<int>f;
        for(int j=i;j<=n;j++){
            if(find(f,a[j])){
                while(f.back()!=a[j])f.pop_back();
            }
            else f.push_back(a[j]);
        }
        while(!f.empty()){
            dp[f.back()]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}
