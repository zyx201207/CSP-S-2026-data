#include <bits/stdc++.h>
using namespace std;
int n;
deque <pair<int,char>> dq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        dq.push_back({a,c});
    }
    long long cnt=0;
    while(!dq.empty()){
        auto[a1,c1]=dq.front();
        dq.pop_front();
        if(dq.empty()) break;
        auto[a2,c2]=dq.back();

        dq.pop_back();
        long long nw=0;
        if(a1>a2){
            dq.push_front({a1-a2,c1});
            nw=a2;
        }else if(a1<a2){
            dq.push_back({a2-a1,c2});
            nw=a1;
        }else if(a1==a2){
            nw=a1;
        }
        if(c1!=c2){
            cnt+=nw;
        }
    }

    cout<<cnt;
}
//9:14 AC (fan tang in 9:00   else faster than 9:14)
