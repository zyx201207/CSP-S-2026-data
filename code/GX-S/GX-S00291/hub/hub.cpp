#include <bits/stdc++.h>
using namespace std;
int smallest = 999999999;
bool arr[5000][5000];
bool state[5000];
int n,k,c,t;
int res2;
fstream input,output;
void dfs(int o,int p){
    if(p == k){
        for(int i = 0;i<n;i++){
            int res1 = 999999999;
            for(int j = i+1;j<n;j++){
                if(state[j] == 1 && arr[i][j] == 1)res1 = min(res1,j-i);
            }
            res2 = max(res1,res2);
        }
    }
    if(o == n)return;
    for(int i = o;i<n;i++){
        state[i] = 1;
        dfs(o+1,p+1);
        state[i] = 0;
        dfs(o+1,p);
    }
}
void group(){
    input >> n >> k;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            arr[i][j] = 0;
        }
        state[i] = 0;
    }
    for(int i = 0;i<n-1;i++){
        int aaa,bbb;
        input >> aaa >> bbb;
        if(aaa < bbb)arr[aaa][bbb] = 1;
        else arr[bbb][aaa] = 1;
    }
    res2 = 0;
    dfs(0,0);
    cout << res2 << endl;
}
int main(){
    input.open("hub.in",ios_base::in);
    output.open("hub.out",ios_base::out);
    input >> c >> t;
    for(int i = 0;i<t;i++){
        group();
    }
    return 0;
}