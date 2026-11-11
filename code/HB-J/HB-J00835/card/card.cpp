#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
bitset<300005>exist;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<int>res(m+1),kards(n+1);
    for(int i=1;i<=n;i++){
        cin>>kards[i];
    }
    vector<int>curr(n+1);
    for(int i=1;i<=n;i++){
        exist.set();exist.flip();
        for(int j=i;j<=n;j++){
            if(!exist[kards[j]]){
                curr.push_back(kards[j]);
                exist[kards[j]]=true;
            }else{
                while(curr.back()!=kards[j]){
                    exist[curr.back()]=false;
                    curr.pop_back();
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(exist[i]){
                res[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<res[i]<<' ';
    }
    return 0;
}
/*
100
60?
60?
60?
*/