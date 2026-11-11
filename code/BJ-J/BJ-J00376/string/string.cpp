#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
struct node{
    int num;
    char c;
};
deque<node> q;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        node x;
        cin>>x.num>>x.c;
        q.push_back(x);
    }
    while(q.size()>1){
        node f=q.front();
        node b=q.back();
        q.pop_front();
        q.pop_back();
        if(f.c!=b.c) ans+=min(f.num,b.num);
        if(f.num>b.num){
            f.num-=b.num;
            q.push_front(f);
        }
        else if(f.num<b.num){
            b.num-=f.num;
            q.push_back(b);
        }
    }
    cout<<ans;
    return 0;
}

