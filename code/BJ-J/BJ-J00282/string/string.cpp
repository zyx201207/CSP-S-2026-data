#include<bits/stdc++.h>
using namespace std;
int n,x;
long long tnt;
string s;
char ch;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>ch;
        for(int j=1;j<=x;j++){
            s+=ch;
        }
    }
    for(int l=0,r=s.size()-1;l<s.size()/2;l++,r--){
        if(s[l]!=s[r]){
            tnt++;
        }
    }
    cout<<tnt;
    return 0;
}