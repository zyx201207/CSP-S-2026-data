#include<bits/stdc++.h>
using namespace std;
vector<int> s;
int n,m,ans=0;
void dfs(int idx,int i,string a){
    cout<<idx<<' '<<i<<' '<<a<<endl;
    if(idx>=m){
        int sum=pow(2,30)-1;
        for(int j=0;j<a.size();j++){
            if(a[j]=='1')sum&=s[j];
        }
        ans=max(ans,sum);
        return;
    }
    i++;
    for(;i<n;i++){
        dfs(idx+1,i,a+'1');
        dfs(idx,i,a+'0');
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.push_back(x);
    }
    dfs(1,0,"1");
    dfs(0,0,"0");
    cout<<ans;
    return 0;
}
