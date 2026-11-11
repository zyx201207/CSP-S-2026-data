#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    int c;
    cin>>c;
    if(a==b){
        cout<<c;
    }
    if(a!=b){
        c++;
        cout<<c;
    }
    if(a==b) cout<<0;
    return 0;
}
