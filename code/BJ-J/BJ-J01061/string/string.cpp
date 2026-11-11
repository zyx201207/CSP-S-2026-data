#include<bits/stdc++.h>
using namespace std;
string s="";
long long n,minn=1e9;
char l_maxn='a',l_minn='z';
bool is_huiwen(string str){
    string tmp=str;
    reverse(str.begin(),str.end());
    if(str==tmp){
        return true;
    }
    else{
        return false;
    }
}
void dfs(long long index,long long step){
    char c=s[index];
    if(step>=minn){
        return ;
    }
    if(index==s.size()+1){
        return ;
    }
    if(is_huiwen(s)){
        minn=min(minn,step);
    }
    for(char i=l_minn;i<=l_maxn;i++){
        s[index]=i;
        dfs(index+1,step+1);
    }
    s[index]=c;
    return ;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(long long i=1;i<=n;i++){
        char c;
        long long tmp;
        cin>>tmp>>c;
        for(long long j=1;j<=tmp;j++){
            s+=c;
        }
        l_maxn=max(l_maxn,c);
        l_minn=min(l_minn,c);
    }
    dfs(0,0);
    cout<<minn;
    return 0;
}
