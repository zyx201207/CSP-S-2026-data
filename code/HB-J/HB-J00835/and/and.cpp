#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
int dfs(vector<int>&v,int curr,int m,int pos,int andsum){
    if(curr==m){
        return andsum;
    }
    if(pos>v.size()){
        return andsum;
    }
    if(m-curr>v.size()-curr+1){
        return 0;
    }
    return max(dfs(v,curr+1,m,pos+1,andsum&v[pos]),dfs(v,curr,m,pos+1,andsum));
}
void build(vector<int>&data,vector<int>&tree,int l,int r,int rt=1){
    if(l==r){
        tree[rt]=data[l];
        return;
    }else{
        int mid=l+(r-l)/2;
        build(data,tree,l,mid,rt*2);
        build(data,tree,mid+1,r,rt*2+1);
        tree[rt]=tree[rt*2]&tree[rt*2+1];
    }
}
int query(vector<int>&tree,int l,int r,int ql,int qr,int rt=1){
    if(ql<=l&&r<=qr){
        return tree[rt];
    }else if(ql>r||qr<l){
        return 0xffffffff;
    }else{
        int mid=l+(r-l)/2;
        return query(tree,l,mid,ql,qr,rt*2)&query(tree,mid+1,r,ql,qr,rt*2+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<int>v(n+1);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(m==1){
        cout<<*max_element(v.begin(),v.end());
        return 0;
    }else if(m==2){
        int res=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                res=max(res,v[i]&v[j]);
            }
        }
        cout<<res;
        return 0;
    }else if(m==n){
        int res=v[0];
        for(int i=1;i<n;i++){
            res&=v[i];
        }
        return res;
    }else if(m==n-1){
        vector<int>tree(4*n+5);
        build(v,tree,1,n);
        int res=0;
        res=max(res,query(tree,1,n,2,n));
        res=max(res,query(tree,1,n,1,n-1));
        for(int i=2;i<n;i++){
            res=max(res,query(tree,1,n,1,i-1)&query(tree,1,n,i+1,n));
        }
        cout<<res;
        return 0;
    }
    cout<<dfs(v,0,m,1,0xffffffff);
    return 0;
}
/*
Lately I've been I've been losing sleep
I've become so numb I can't feel you there
They say flowers fade cause their beauty can't be weighed with the flowers so fake
Bring me out Come and find me in the dark now
I'm gonna change you Like a remix Then I'll raise you Like a phoenix
I-I-I got this feeling yeah you know
How could we not talk about family when family's all that we got
*/