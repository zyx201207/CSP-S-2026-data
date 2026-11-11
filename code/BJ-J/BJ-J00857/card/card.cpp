#include<bits/stdc++.h>
using namespace std;
vector<int>a;
bool vis[300005];
int c[300005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int _=1;_<=n;_++){
        memset(vis,0,sizeof vis);
        vector<int>desk;
        for(int j=_-1;j<a.size();j++){
            int i=a[j];
            if(vis[i]){
                for(int k=(int)desk.size()-1;k>=0;k--){
                    bool flag=0;
                    if(a[k]==i)flag=1;
                    desk.pop_back();
                    if(flag)break;
                }
            }vis[i]=1;
            desk.push_back(i);
        }
        for(auto i:desk){
            c[i]++;
            //cout<<i<<" ";
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
