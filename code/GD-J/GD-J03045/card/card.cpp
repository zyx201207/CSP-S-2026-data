#include<bits/stdc++.h>
using namespace std;
int find(int a,vector<int>&v){
    for(int i=0;i<v.size();i++){
       // cout<<v[i]<<' ';
        if(v[i]==a){
            return i;
        }
    }return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int >pai,ans(m,0);
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        pai.push_back(a);
    }for(int i=0;i<n;i++){
        vector<int>card;
        for(int j=i;j<n;j++){
            int f=find(pai[j],card);
            //cout<<'\n'<<pai[j]<<f<<'\n';
            if(f==-1){
                card.push_back(pai[j]);
            }else{
                card.erase(card.begin()+f+1,card.end());
            }
        }for(int c:card){
            ans[c-1]++;
        }
    }for(int c:ans){
        cout<<c<<' ';
    }
    return 0;
}