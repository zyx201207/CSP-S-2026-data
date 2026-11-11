#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> c;
vector<int> ans;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    c.resize(n,0);
    ans.resize(m+1,0);
    for(int i=0;i<n;i++) cin>>c[i];
    deque<int> q;
    deque<int> lin;
    vector<bool> book(m+1,false);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(book[c[j]]){
               bool flag=true;
               while(!q.empty()){
                    if(q.front()==c[j]) flag=false;
                    if(q.front()!=c[j]&&flag){
                        lin.push_back(q.front());
                        q.pop_front();
                    }
                    book[q.front()]=false;
                    q.pop_front();
               }
               while(!lin.empty()){
                    q.push_back(lin.front());
                    lin.pop_front();
               }
            }
            q.push_back(c[j]);
            book[c[j]]=true;
        }
        while(!q.empty()){
            ans[q.front()]++;
            book[q.front()]=false;
            q.pop_front();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}