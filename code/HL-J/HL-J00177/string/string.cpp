#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        char c;
        cin>>x>>c;
        for(int j=0;j<x;j++){
            s.push_back(c);
        }
    }
    if(s.size()%2==1){
        string c=s.substr(0,s.size()/2);
        string d=s.substr(s.size()/2+1,s.size()/2);
        int ans=0;
        for(int i=0;i<c.size();i++){
            if(c[i]!=d[c.size()-i-1]){
                ans++;
            }
        }
        cout<<ans;
    }
    else{
        string c=s.substr(0,s.size()/2);
        string d=s.substr(s.size()/2,s.size()/2);
        int ans=0;
        for(int i=0;i<c.size();i++){
            if(c[i]!=d[c.size()-i-1]){
                ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
