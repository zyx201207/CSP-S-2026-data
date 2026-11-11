#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,ans[500005]={0};
    int v[500005];
    queue<int> a;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        a.push(x);
    }
    while(!a.empty()){
        int j=1;
        queue<int> b=a;
        set<int> s;
        while(!b.empty()){
            s.insert(b.front());
            b.pop();
        }
        for(int i=0;i<s.size();i++){
            ans[s[i]]+=1;
        }
        a.pop();
    }
    for(int k=1;k<=m;++k)cout<<ans[m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}