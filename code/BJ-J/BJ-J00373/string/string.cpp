#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,char>
#define fi first
#define se second
deque<pii> q;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int s;
        char c;
        cin>>s>>c;
        q.push_back({s,c});
    }
    int res=0;
    while(q.size()){
        if(q.size()==1&&q.front().fi==1) break;
        int mn=min(q.front().fi,q.back().fi);
        if(q.front().se!=q.back().se){
            res+=mn;
        }
        q.front().fi-=mn;
        if(q.front().fi==0) q.pop_front();
        q.back().fi-=mn;
        if(q.back().fi==0) q.pop_back();
    }
    cout<<res;
    return 0;
}

