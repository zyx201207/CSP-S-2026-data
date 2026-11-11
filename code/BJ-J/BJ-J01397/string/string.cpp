#include<bits/stdc++.h>
using namespace std;
string s="";
int dfs(int x,int k){
    //cout<<k<<" ";
    if(x<=s.size()/2){
        return k;
    }
    //cout<<s[x]<<" "<<s[s.size()-1-x]<<endl;
    if(s[x]==s[s.size()-1-x]){
        dfs(x-1,k);
    }else{
        //cout<<x<<endl;
        dfs(x-1,k+1);
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        char c;
        cin>>c;
        for(int j=1;j<=x;j++)s+=c;
    }
    //cout<<s<<" ";
    cout<<dfs(s.size()-1,0);
    return 0;
}
