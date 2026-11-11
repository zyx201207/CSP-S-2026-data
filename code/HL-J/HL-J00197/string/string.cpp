#include<bits/stdc++.h>
#define int long long
using namespace std;
deque<pair<int,char>>q;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        q.push_back(make_pair(x,c));
    }
    while(q.size()>1){
        int x=q.front().first,y=q.back().first;
        char cx=q.front().second,cy=q.back().second;
        if(cx==cy){
            if(x<y){
                q.back().first-=x;
                q.pop_front();
            }
            else if(x==y) q.pop_front(),q.pop_back();
            else if(x>y){
                q.front().first-=y;
                q.pop_back();
            }
        }
        else{
            if(x<y){
                sum+=x;
                q.back().first-=x;
                q.pop_front();
            }
            if(x==y){
                sum+=x;
                q.pop_front();
                q.pop_back();
            }
            if(x>y){
                sum+=y;
                q.front().first-=y;
                q.pop_back();
            }
        }
    }
    cout<<sum;
    return 0;
}
