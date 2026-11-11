#include<bits/stdc++.h>
using namespace std;
char u[10000000000];
char d[10000000000];
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    long long ans;
    cin>>ans;
    int a;
    char b;
    for(int i=0;i<ans;i++){
        cin>>a>>b;
        for(int j=0;j<a;j++){
             u[i]=b;
        }
    }
    d=reverse(u.begin(),u.end());
    if(d==u){
        cout<<0;
    }
    return 0;
}
