#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x[10007],cnt=0;
    char c[10007];
    string s="";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>c[i];
        for(int j=0;j<x[i];j++){
            s.push_back(c[i]);
        }
    }
    string a,b;
    if(s.size()%2){
        a=s.substr(0,s.size()/2);
        b=s.substr(s.size()/2+1,s.size()/2);
    }else{
        a=s.substr(0,s.size()/2);
        b=s.substr(s.size()/2,s.size()/2);
    }
    reverse(b.begin(),b.end());
    for(int i=0;i<b.size();i++){
        if(a[i]!=b[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
