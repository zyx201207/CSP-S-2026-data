#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
stack<int> s;
map<int,bool> mp;
map<int,int> q;
map<int,int> ans;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i,j,k;
    cin>>n>>m;
    for (i=0;i<n;i++) cin>>a[i];
    for (i=0;i<n;i++){
        mp.clear();
        q.clear();
        while (!s.empty()) s.pop();
        for (j=i;j<n;j++){
            if (mp[a[j]]){
                int len=s.size();
                for (k=q[a[j]];(k<len)&&(!s.empty());k++){
                    mp[s.top()]=0;
                    s.pop();
                }
            }
            s.push(a[j]);
            q[a[j]]=s.size()-1;
            mp[a[j]]=1;
        }
        for (auto it=mp.begin();it!=mp.end();it++) if (it->second) ans[it->first]++;
    }
    for (i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
