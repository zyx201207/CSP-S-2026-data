#include<bits/stdc++.h>
using namespace std;
int n;
string s="";
bool vis[26];
bool clac(string a){
    for(int i=0;i<=a.size()/2;i++){
        if(a[i]!=a[a.size()-i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        vis[(int)(c-'a')]=true;
        for(int i=0;i<a;i++){
            s+=c;
        }
    }
    queue<pair<string,pair<int,int>>> q;
    q.push({s,{0,0}});
    while(!q.empty()){
        string tmp=q.front().first;
        int x=q.front().second.first;
        int cnt=q.front().second.second;
        q.pop();
        //cout<<tmp<<'\n';
        if(clac(tmp)){
            cout<<cnt;
            return 0;
        }
        for(int i=0;i<26;i++){
            if(vis[i]){
                string tmp1=tmp;
                tmp1[x]=(char)(i+'a');
                q.push({tmp1,{x+1,cnt+1}});
            }
        }
    }
    return 0;
}
