#include<bits/stdc++.h>
using namespace std;
string s;
int n;
bool is_huiwen(string s,int n){
    s=" "+s;
    for(int i=1;i<=n;i++)
        if(s[i]!=s[n-i+1])
            return false;
    return true;
}
void turn_to_huiwen(){
    int sn=s.size();
    for(int i=1;i<=sn;i++)
        if(s[i]!=s[sn-i+1]){
            s[sn-i+1]=s[i];
        }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)
            s = s + c;
    }
    int sn=s.size(),cnt=0;;
    string os=s;
    if(is_huiwen(s,sn)){
        cout<<0;
        return 0;
    }
    turn_to_huiwen();
    for(int i=1;i<=sn;i++)
        if(s[i]!=os[i])
            cnt++;
    cout<<cnt;
    return 0;
}