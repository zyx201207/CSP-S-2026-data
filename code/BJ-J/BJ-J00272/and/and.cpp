#include<bits/stdc++.h>
using namespace std;

int n, m, ans=0;
vector<int> vec, pei;
void dfs(int n){
         int shu = pei[0];
         shu = for(int i=1;i<m;i++)pei[i]&shu;
         if(shu>ans) ans = shu;
         for(int i = 0;i<m;i++){
            pei[dfs]= vec[i];
            dfs[i];
         }
    }
int main(){
    freopen('and.in', 'r', stdin);
    freopen('and.out', 'w', stdout);
    cin >> n >> m;
    vec.resize(n+1);
    pei.resize(m+1);
    for(int i = 0;i<n;i++) cin>>vec[i];
    dfs(0);
    cout << ans;

}