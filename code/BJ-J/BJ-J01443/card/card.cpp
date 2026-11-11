#include<bits/stdc++.h>
using namespace std;
int a[500005], b[500005];
stack<int>s;
void check(int x){
    stack<int>s1;
    while(!s.empty()){
        s1.push(s.top());
        if(s.top()==x){
            while(!s1.empty()){
                s1.pop();
            }
        }
        s.pop();
    }
    while(!s1.empty()){
        s.push(s1.top());
        s1.pop();
    }
    s.push(x);
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int m, n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            check(a[j]);
        }
        while(!s.empty()){
            b[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
}
