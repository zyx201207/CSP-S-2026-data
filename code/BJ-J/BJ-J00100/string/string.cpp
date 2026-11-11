#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n,cnt=0;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        char c;
        cin>>c;
        while(a--){
            s+=c;
        }
    }
    for(int i=0;i*2<s.size();i++){
        if(s[i]!=s[s.size()-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}