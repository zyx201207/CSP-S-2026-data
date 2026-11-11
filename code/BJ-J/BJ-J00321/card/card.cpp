#include <bits/stdc++.h>

using namespace std;

const int N=5e5+10;
const int M=3e5+10;
int n,m;
int a[N];
int b[M];

queue<int>q;

bool check(int x){
    queue<int>ls;
    queue<int>ls1;
    while(!q.empty()){
        ls.push(q.front());
        ls1.push(q.front());
        q.pop();
    }
    while(!ls1.empty()){
        q.push(ls1.front());
        ls1.pop();
    }
    while(!ls.empty()){
        if(ls.front()==x){
            return true;
        }
        ls.pop();
    }
    return false;
}

void solve(int x){
    queue <int> ls;
    while(q.front()!=x){
        ls.push(q.front());
        q.pop();
    }
    while(!q.empty()) q.pop();
    while(!ls.empty()) q.push(ls.front()),ls.pop();
    q.push(x);
    return;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(!check(a[j])){
                q.push(a[j]);
            }else{
                solve(a[j]);
            }
        }
        while(!q.empty()){
            b[q.front()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
return 0;
}
