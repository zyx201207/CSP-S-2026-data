#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+5,M = 3e5+5;
int n,m,a[N],ans[M];

void play(int st){
    stack<int> card;
    map<int,int> mp;
    for(int i = st; i <= n; i++){
        if(!mp[a[i]]){
            while(card.top() != a[i]){
                mp[card.top()]--;
                card.pop();
            }
        }else{
            card.push(a[i]);
            mp[a[i]]++;
        }
    }
    while(!card.empty()){
        ans[card.top()]++;
        card.pop();
    }
}

signed main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        play(i);
    }

    for(int i = 1; i <= m; i++) cout << ans[i] << ' ';

    return 0;
}

