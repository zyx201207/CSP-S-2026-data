#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s=" ";
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int i=0;i<a;i++){
            s+=c;
        }
    }
    s+=' ';
    int cnt=0;
    int ss=s.size();
    if(ss%2==0){
        ss/=2;
        for(int i=0;i<ss;i++){
            if(s[i]!=s[s.size()-i-1]) cnt++;
        }
        cout<<cnt;
    }
    else{
        ss/=2;
        for(int i=0;i<ss;i++){
            if(s[i]!=s[s.size()-i-1]) {cnt++;
        } }
        cout<<cnt;

    }
    return 0;
}












