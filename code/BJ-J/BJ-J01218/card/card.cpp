#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
set<int> s;
int a[500005];
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        mp[a[i]] = 0;
    }
    for(int i = 1;i <= n;i++){
        s.clear();
        for(int j = i;j <= n;j++){
            if(!s.empty()){
                if(s.count(a[j]) == 1){//you
                    int x;
                    for(int k = i;k < j;k++){
                        if(a[k] == a[j] && s.count(a[k])){
                            x = k;
                            break;
                        }
                    }
                    for(int k = x;k < j;k++){
                        if(s.count(a[k]) == 1){
                            mp[a[k]]--;
                            s.erase(a[k]);
                        }
                    }
                }
            }
            mp[a[j]]++;
            s.insert(a[j]);
        }
    }
    for(int i = 1;i < m;i++){
        cout<<mp[i]<<" ";
    }
    cout<<mp[m];
    return 0;
}