#include <bits/stdc++.h>
using namespace std;
unsigned long long a[200020],as = -1;
int n,m;
void dfs(long long k,;unsigned long long tmp,int step){
    if(step == m){
        as = max(as,tmp);
        return;
    }
    for(int i = k + 1;i <= n;i++){
        dfs(i,a[k] | a[i],step + 1);
    }
    return;
}
int main(){
    freopen("and.in",'r',stdin);
    freopen("and.out",'w',stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    dfs(1,0,1);
    cout << as << endl;
    return 0;
}