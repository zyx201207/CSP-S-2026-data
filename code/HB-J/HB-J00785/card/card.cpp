#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a;
int b[500100];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cin>>a;
            if(a!=s.top()){
                s.push(a);
            }else{
                s.pop();
            }
        }
        while(!s.empty()){
            b[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i];
    }
    return 0;
}
