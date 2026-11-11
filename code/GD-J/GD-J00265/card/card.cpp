#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int a[500005];
map<int,int> vis[500005];
// map<int,int> mp;
// int lst[5005];
// int p[5005];
// int sum[3005][5005];
// int sumt[3005];
int sum[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        // if(lst[a[i]]){
        //     p[i]=lst[a[i]];
        // }
        // lst[a[i]]=i;
        // for(int j=1;j<=m;j++){
        //     sum[j][i]=sum[j][i-1];
        // }
        // sum[a[i]][i]++;
    }
    if(n>500){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1]){
                sum[a[i]]=i;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<sum[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        vector<int> v;
        for(int j=i;j<=n;j++){
            v.push_back(a[j]);
            for(int k=(int)v.size()-2;k>=0;k--){
                if(v[k]==a[j]){
                    // cout<<"erase"<<endl;
                    v.erase(v.begin()+k+1,v.end());
                    // for(auto l : v){
                    //     cout<<l<<" ";
                    // }
                    // cout<<endl;
                    break;
                }
            }
        }
        for(auto j : v){
            vis[i][j]=1;
        }
    }
    for(int i=1;i<=m;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            cnt+=vis[j][i];
        }
        cout<<cnt<<" ";
    }
    return 0;
}