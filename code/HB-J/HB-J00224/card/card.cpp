#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
using namespace std;
int n,m,x;
vector<bool> v;
int ans[300005];
deque<int> card;
void run(deque<int> hand){
    v.clear();
    v.resize(m+1,0);
    deque<int> stable;
    while(!hand.empty()){
        while(v[hand.front()]&&!stable.empty()){
            v[stable.back()]=0;
            stable.pop_back();
        }
        stable.push_back(hand.front());
        v[hand.front()]=1;
        hand.pop_front();
    }
    for(int i:stable) ans[i]++;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        card.push_back(x);
    }
    while(!card.empty()){
        run(card);
        card.pop_front();
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}