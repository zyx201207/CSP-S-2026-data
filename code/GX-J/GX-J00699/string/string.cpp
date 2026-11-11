#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,x,sum=0;
    char y;
    string s="";
    cin>>n;
    while(n--){
        cin >>x>>y;
        while(x--){
            s+=y;
        }
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i])
            sum++;
    }
    cout <<sum;
    return 0;
}
