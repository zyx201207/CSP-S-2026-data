#include<bits/stdc++.h>
using namespace std;
map<int,bool>mp;
//bool mp[300010];
int n,m,a[500010],cnt[300010];
stack<int>s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(mp[a[j]]){
                while(s.top()!=a[j]){
                    s.pop();
                }
                s.pop();
            }
            s.push(a[j]);
            mp[a[j]]=1;
        }
        while(!s.size()==0){
            cnt[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}