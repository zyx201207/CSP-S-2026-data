#include<bits/stdc++.h>
#define int long long
using namespace std;
deque<pair<char,int> > d;
int n,ans=0;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char a;
        int b;
        cin>>b>>a;
        pair<char,int> pp;
        pp.first=a;
        pp.second=b;
        d.push_back(pp);
    }
    while(d.size()>1){
        pair<char,int> b,e,pp;
        b=d.front();
        d.pop_front();
        e=d.back();
        d.pop_back();
        if(b.second>e.second){
            if(b.first==e.first){
                pp.second=b.second-e.second;
                pp.first=b.first;
                d.push_front(pp);
            }
            else{
                ans+=e.second;
                b.second-=e.second;
                d.push_front(b);
            }
        }
        else if(e.second>b.second){
            if(b.first==e.first){
                pp.second=e.second-b.second;
                pp.first=b.first;
                d.push_back(pp);
            }
            else{
                ans+=b.second;
                e.second-=b.second;
                d.push_back(e);
            }
        }
        else{
            if(b.first==e.first){
            }
            else{
                ans+=e.second;
            }
        }
    }
    cout<<ans;
    return 0;
}
