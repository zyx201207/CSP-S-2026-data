#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0,s,y,x;
    char c;
    string a="";
    cin>>n;
    for(long long i=0;i<n;i++){
    cin>>s>>c;
    while(s--){
    a+=c;
    }
    }
    for(x=0;x>y;x++){
    for(y=a.size();y<x;y++){
    if(a[x]==a[y]){
    cnt++;
    }
    }
    }
    cout<<cnt;
    return 0;
   }
