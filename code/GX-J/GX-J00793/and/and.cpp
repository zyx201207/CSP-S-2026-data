#include <bits/stdc++.h>
using namespace std;
int n,m,biggest = 0;
int a[200000];
void dfs(int i,int used,int res){
    if(i >= n || used >= m){
        if(used == m)biggest = max(res,biggest);
        return;
    }
    // cout << res << "-\n";
    dfs(i+1,used+1,res&a[i]);
    dfs(i+1,used,res);
}
int main(){
    fstream input;
    fstream output;
    input.open("and.in",ios_base::in);
    output.open("and.out",ios_base::out);
    input >> n >> m;
    for(int i = 0;i<n;i++){
        input >> a[i];
    }
    dfs(0,0,-1);
    output << biggest;
    // cout << int(a[0]&a[1]&a[2]);
    input.close();
    output.close();
    return 0;
}