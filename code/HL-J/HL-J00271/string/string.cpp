#include<bits/stdc++.h>
using namespace std;
bool ishuiwen(string s){
    s=" "+s;
    if(s.size()%2){
        for(int i=1;i<=s.size()/2;i++){
            if(s[i]!=s[s.size()-i]) return false;
        }
    }else{
        for(int i=1;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i]) return false;
        }
        if(s[s.size()/2]!=s[s.size()/2+1]) return false;
    }
    return true;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    string s="";
    while(n--){
        int a;char c;
        cin>>a>>c;
        while(a--) s+=c;
    }
    if(ishuiwen(s)){
        cout<<"0";return 0;
    }
    string s1,s2;
    int i=0,j=s.size()-1;
    while(i<=j){
        s1[i]=s[i];
        s2[s.size()-1-j]=s[j];
        i++;j--;
    }
    int cnt=0;
    for(int k=0;k<i;k++){
        if(s1[k]!=s2[k]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

