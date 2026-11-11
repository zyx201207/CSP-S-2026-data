#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[300010];
bool is[300010];
struct Node {
    int id,sc;
    bool operator>(Node x) const {
        return id>x.id;
    }
};
stack<Node>a;
priority_queue<Node>q;
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1,x;i<=n;i++) {
        cin>>x;
        if(is[x]) {
            while(a.top().sc!=x) a.pop();
            a.pop();
            a.push({i,x});
        }
        else {
            is[x]=1;
            a.push({i,x});
        }

    }
    for(int i=2;i<=n;i++) {
        while(!a.empty()){
            q.push(a.top());
            is[a.top().sc]=0;
            a.pop();
        }
        while(!q.empty()) {
            Node k;bool flag=0;
            if(q.top().id>=i) k=q.top(),flag=1;
            q.pop();
            if(is[k.sc]&&flag) {
                while(a.top().sc!=k.sc) a.pop();
                a.pop();
                a.push(k);
            }
            else if(flag){
                is[k.sc]=1;
                a.push(k);
            }
        }
    }
    while(!a.empty()) {
        cnt[a.top().sc]++;
        a.pop();
    }
    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<' ';
    return 0;
}
