#include <bits/stdc++.h>

using namespace std;
struct node{
    int child[2];
    int o=0;
}root;
vector<node> trie;
long long result=0;
int m;
void build(long long n){
    int i=0;
    while(n>0){
        int c=n&1;
        if(trie[i].child[c]==0){
            trie[i].child[c]=trie.size();
            i=trie.size();
            trie.push_back({{0,0},1});
        }else{
            i=trie[i].child[c];
            trie[i].o++;
        }
        n>>=1;
    }
}
void dfs(int i,long long ans,int wei){
    result=max(ans,result);
    if(trie[trie[i].child[0]].o>=m){
        dfs(trie[i].child[0],ans,wei+1);
    }
    if(trie[trie[i].child[1]].o>=m){
        ans+=1<<wei;
        dfs(trie[i].child[1],ans,wei+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    root={{0,0},0};
    trie.push_back(root);
    int n;cin>>n;
    cin>>m;
    long long temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        build(temp);
    }
    dfs(0,0,0);
    cout<<result;
}
