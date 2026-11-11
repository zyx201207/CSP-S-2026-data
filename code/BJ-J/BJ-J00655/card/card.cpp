#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+2;
int n,m,a[maxn];
map<int,int> mp;
queue<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int x=a[j];
            if(q.empty()){
                q.push(x);
                continue;
            }
            if(x!=q.front()) q.push(x);
            else{
                while(!q.empty()) q.pop();
                q.push(x);
            }
        }

        while(!q.empty()){
            mp[q.front()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<mp[i]<<' ';
    cout<<'\n';
    return 0;
}
