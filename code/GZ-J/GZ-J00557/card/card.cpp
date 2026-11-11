#include<bits/stdc++.h>
using namespace std;
void f(vector<int>&card,vector<int>&ans){
    vector<int>now;
    unordered_map<int,bool>m;
    for(int&i:card){
        if(!m[i])m[i]=true;
        else{
            int p=now.size();
            for(int j=0;j<now.size();j++){
                if(now[j]==i){
                    for(int k=0;k<p-j;k++){
                        m[now[now.size()-1]]=false;
                        now.pop_back();
                    }
                    break;
                }
            }
        }
        now.push_back(i);
    }
}
int n,m;
int main(){
    freopen("card.in","r",stdin);
    reopen("card.out","w",stdout);
    cin>>n>>m;
    vector<int>card(n),ans(m);
    for(int&i:card)
        cin>>i;
    for(int i=0;i<n;i++){
        f(card,ans);
        card.erase(card.begin());
    }
    for(int&i:ans)
        cout<<i<<' ';
    return 0;
}
