#include<bits/stdc++.h>
using namespace std;
string s,sf1,sf2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char l;
        cin>>l>>a;
        for(int j=1;j<=a;j++){
            s+=l;
        }
    }
    if(s.size()%2==0) {
        for(int i=0;i<s.size()/2;i++){
            sf1+=s[i];
            sf2+=s[i+s.size()/2];
        }
        sf2+=sf1;
        for(int i=1;i<s.size();i++){
            if(sf2[i]!=s[i]) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
