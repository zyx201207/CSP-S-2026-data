#include <bits/stdc++.h>
using namespace std;
int n,m;
long long biggest = 0;
int a[500000];
int b[500000];
void calc(){
    for(int i = 0;i<n;i++){
        b[i] = a[i];
    }
    sort(b,b+n);
    // for(int i = 0;i<n;i++){
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    long long res = 1;
    for(int i = 1;i<n;i++){
        if(b[i-1] == b[i])res++;
        else res = 1;
        if(biggest < res)biggest = res;
    }
}
void solve(int t){
    if(t >= m){
        calc();
        return;
    }
    for(int i = 0;i<n;i++){
        a[i]++;
        solve(t+1);
        a[i]--;
    }
}
int main(){
    fstream input,output;
    input.open("crystal.in",ios_base::in);
    output.open("crystal.out",ios_base::out);
    input >> n >> m;
    for(int i = 0;i<n;i++){
        input >> a[i];
    }
    solve(0);
    // cout << a[2];
    output << biggest;
    return 0;
}