#include <bits/stdc++.h>
using namespace std;
const int N=500010,M=300010;
long long n,m;
int count[M],in[N],res[M];
stack<int> q,l;
bool flag[M];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>in[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
             if(count[in[j]]){
                  while(q.top()!=in[j]){
                      int x=q.top();
                      count[x]--;
                      q.pop();
                  }
             }else{
                  count[in[j]]++;
                  q.push_back(in[j]];
             }
        }
        while(!q.empty()){
             int xx=q.top();
             l.push_back(xx);
             flag[xx]=true;
             q.pop();
        }
        for(int j=1;j<=m;j++){
            if(flag[j])res[j]++;
        }
        while(!l.empty()){
             int xx=l.top();
             q.push_back(xx);
             flag[xx]=false;
             l.pop();
        }
    }
    for(int j=1;j<=m;j++){
         cout<<res[j]<<' ';
    }
    return 0;
}

