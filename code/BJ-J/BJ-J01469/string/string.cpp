#include<bits/stdc++.h>
using namespace std;
int m;
int p=0;
int z=0;
string h;
string t;
int com(char k1,char k2){
    if(k1!=k2){
    return 1;
    }else{
    return 0;
    }
}
int main(){
    int n;
    cin>>n;
    while(n--){
        cin>>m>>h;
        while(m--){
        t[z]=h[0];
        z++;
        }
    }
    int a=t.size();
    for(int u=0;u<a/2;u++){
       p+=com(t[u],t[a-u]);
    }
    cout<<p;
    return 0;
}
