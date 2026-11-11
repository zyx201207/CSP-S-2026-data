#include <bits/stdc++.h>
using namespace std;


int m,n,a[10000001] = {},max1 = 0;
int and1(int c, int b){
    int a1[31], b1[31],c1[31],cnt = 0;
    while(a){
        a1[cnt] = c % 2;
        cnt++;
        c = c / 2;
    }
    cnt = 0;
    while(b){
        b1[cnt] = b % 2;
        cnt++;
        b = b / 2;
    }
    for(int i = 0;i < 31;i++){
        if(a1[i] && b1[i]){
            c1[i] = 1;
        }
        else{
            c1[i] = 0;
        }
    }
    int sum = 1;
    cnt = 0;
    for(int i = 0;i < 31;i++){
        cnt += c1[i] * sum;
        sum *= 2;
    }
    return cnt;
}
int dfs(int a1, int b, int c){
    if(a1 == n){
        max1 = max(max1,b);
        return 0;
    }
    for(int i = c+1;i < m;i++){
        dfs(a1+1,and1(b, a[i]),i);
    }
}


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> m >> n;
    for(int i = 0;i < m;i++){
        cin >> a[i];
    }
    for(int i = 0;i < m;i++){
        for(int j = i+1;j < m;j++){
            if(a[i] > a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    dfs(0,2147483648,-1);
    cout << max1;
    return 0;
}