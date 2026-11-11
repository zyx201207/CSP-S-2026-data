#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    cin>>n;
    int a[n];
    char b[n];
    string s;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        for(int j=0;j<a[i];j++){
            s+=b[i];
        }
    }
    string c;
    for(int i=s.size();i>0;i--){
        c+=s[i];
    }
    if(c==s){cout<<0;return 0;}
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1]){sum+=1;}
    }
    cout<<sum;
    return 0;
}
