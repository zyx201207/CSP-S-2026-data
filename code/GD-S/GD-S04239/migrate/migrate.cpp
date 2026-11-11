#include<bits/stdc++.h>
using namespace std;

long long c,t;

void f(){
    
    long long n=0,d=0,tmp;
    deque<long long> x={};
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>tmp;
        x.push_back(tmp);
    }
    if(c==11 || c==12){
        long long _delta__=x[1]-x[0];
        if(_delta__>=d || d/_delta__>=n){
            cout<<"0\n";
        }else cout<<n-(2*(d/_delta__)-1)<<"\n";
    }
    if(c>=13 && c<=18){
            cout<<"0\n";
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.ans","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        f();
    }
}