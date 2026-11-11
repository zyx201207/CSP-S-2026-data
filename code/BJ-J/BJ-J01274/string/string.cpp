#include<bits/stdc++.h>
using namespace std;
string s;
int n,x,js;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        string c;
        cin>>x>>c;
        for(int j=0;j<x;j++) s+=c;
    }
    string s1=s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]!=s1[i]) js++;
    }
    cout<<js/2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}