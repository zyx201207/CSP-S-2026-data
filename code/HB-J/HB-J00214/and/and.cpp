/*
CSP-J2 2026 RP++
C 115min 55pts.
*/
#include<bits/stdc++.h>
using namespace std;
const int maxN=2e5+10;
int n,m,num[maxN],ans=0;
bool flag=1;
//int trie[35][3],tot=0
// vector<int> cho[80],chi[80];
// string bina[200010];
// void add(string s,int id){
//     int pos=0,nxt=0;
//     for(int i=0;i<s.length();i++){
//         nxt=s[i]-'0';
//         if(!trie[pos][nxt]) trie[pos][nxt]=++tot;
//         pos=trie[nxt][pos];
//         if(nxt==0) cho[i].push_back(id);
//         else chi[i].push_back(id);
//     }
// }
inline int qand(int x,int y){
    int res=0,base=1;
    while(x>0&&y>0){
        if((x%2)==(y%2)) res+=base;
        base*=2;
        x/=2;
        y/=2;
    }
    return res;
}
void dfs(int pos,int val,int chosen){
    if(chosen==m){
        ans=max(ans,val);
        return;
    }
    if(n-pos+1<m-chosen) return;
    dfs(pos+1,val,chosen);
    if(val==0) val=num[pos];
    dfs(pos+1,qand(val,num[pos]),chosen+1);
}
int main(){
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(false);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if((1<<(int)log2(num[i]+1))!=(num[i]+1)) flag=0;
        // int tmp=num[i];
        // string bin="";
        // while(tmp){
        //     bin+=(char)(tmp%2+'0');
        //     tmp/=2;
        // }
        // reverse(bin.begin(),bin.end());
        // bina[num[i]]=bin;
        // add(bin,i);
    }
    // sort(num+1,num+n+1,greater<int>());
    // string tar=bina[num[m]];
    // vector<int> stand;
    // int ans=num[m];
    // for(int i=0;i<tar.length();i++){
    //     if(tar[i]=='1'){
    //         if(chi[i].size()>=m){
    //             if(stand.empty()) stand=chi[i];
    //             else{
    //                 int cnt=0;
    //                 for(int j:chi[i]){
    //                     if(find(stand.begin(),stand.end(),j)!=stand.end()){
    //                         cnt++;
    //                     }
    //                 }
    //                 if(cnt<m) ans-=(1<<(tar.length()-i-1));
    //             }
    //         }else{
    //             ans-=(1<<(tar.length()-i-1));
    //         }
    //     }else{
    //         if(cho[i].size()>=m){
    //             if(stand.empty()) stand=cho[i];
    //             else{
    //                 int cnt=0;
    //                 for(int j:cho[i]){
    //                     if(find(stand.begin(),stand.end(),j)!=stand.end()){
    //                         cnt++;
    //                     }
    //                 }if(cnt>=m) ans+=(1<<(tar.length()-i-1));
    //             }
    //         }
    //     }
    // }
    // cout<<ans<<endl;
    if(flag){
        sort(num+1,num+n+1,greater<int>());
        ans=num[m];
    }//special A
    else if(m==n){
        ans=num[1];
        for(int i=2;i<=n;i++){
            ans=qand(ans,num[i]);
        }
    }
    else dfs(1,0,0);
    cout<<ans;
    return 0;
}