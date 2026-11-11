#include<bits/stdc++.h>
using namespace std;
int n;
deque<pair<char,int>>dq;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n--){
        int x;
        char c;
        cin>>x>>c;
        dq.push_back(make_pair(c,x));
    }
    long long res=0;
    while(dq.size()>1){
        auto l=dq.front();
        auto r=dq.back();
        dq.pop_front();
        dq.pop_back();
        int len=min(l.second,r.second);
        res+=len*(l.first!=r.first);
        l.second-=len;
        r.second-=len;
        if(l.second)dq.push_front(l);
        if(r.second)dq.push_back(r);
    }
    cout<<res<<"\n";
}