#include<bits/stdc++.h>
using namespace std;
int n,a;
char b;
int cnt=0;
vector<char>s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        for(int j=0;j<a;j++){
            s.push_back(b);
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-i-1]&&i<s.size()-i-1)cnt++;
    }
    cout<<cnt;
    return 0;
}