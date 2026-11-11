#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    deque<pair<size_t,char>> dq;
    for(int i=0;i<n;++i){
        int a;
        char c;
        cin>>a>>c;
        dq.push_back({a,c});
    }
    size_t ans=0;
    while(dq.size()>1){
        auto f=dq.front();
        auto b=dq.back();
        //cout<<"f={"<<f.first<<","<<f.second<<"}"<<endl;
        //cout<<"b={"<<b.first<<","<<b.second<<"}"<<endl;
        dq.pop_back();
        dq.pop_front();

        if(f.first>b.first){
            dq.push_front({f.first-b.first,f.second});
        }else if(f.first<b.first){
            dq.push_back({b.first-f.first,b.second});
        }
        if(f.second!=b.second){
            ans+=min(f.first,b.first);
        }
        //getchar();
    }
    cout<<ans;
}