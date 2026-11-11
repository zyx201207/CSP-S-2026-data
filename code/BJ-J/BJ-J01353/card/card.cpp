#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
#include<stdio.h>
constexpr int N=5e5+1;
int a[N];
vector<int> vec;
unordered_map<int,int> ans,card;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(i!=1){
            card.clear();
            vec.clear();
        }
        vec.push_back(0);
        for(int j=i;j<=n;j++){
            if(card.find(a[j])==card.end()){
                card.insert(make_pair(a[j],vec.size()));
                vec.push_back(a[j]);
            }else{
                int tmp=card.at(a[j]);
                for(int k=tmp;k<vec.size();k++)card.erase(vec[k]);
                vec.resize(tmp);
                vec.push_back(a[j]);
                card.insert(make_pair(a[j],vec.size()));
            }
        }
        for(auto x : card)ans[x.first]++;
    }
    for(int i=1;i<=m;i++){
        if(ans.find(i)==ans.end())cout<<0;
        else cout<<ans.at(i);
        cout.put(' ');
    }
    return 0;
}