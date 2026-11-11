#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
vector<long long>num,a;
void dfs(int u){
    long long an=0;
    if(u==m+1){
        an=a[num[1]];
  //      cout<<num[1]<<' ';
        for(int i=2;i<=m;i++){
                if(num[i]==num[i-1]){
                    return;}
 //               cout<<num[i]<<' ';
                an=an&a[num[i]];}
 //       cout<<'\n';
        ans=max(an,ans);
        return;}
    num.push_back(0);
    for(int i=num[u-1]+1;i<a.size();i++){
        num[u]=i;
        dfs(u+1);}}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long x;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);}
 //   for(int i=0;i<n;i++){
  //      cout<<a[i]<<' ';}
    dfs(1);
    num[0]=-1;
    cout<<ans;
    }
