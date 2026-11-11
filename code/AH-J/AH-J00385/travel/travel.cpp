#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

string start(string s,int len){
    return (s.substr(0,len));
}

string cuted(string s,int len){
    return (s.substr((int)s.size()-len,len));
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    string a=cuted(s1,1);
    string b=cuted(s2,1);
    bool f1=(c1==c2);
    bool f2=(start(s1,2)==start(s2,2));
    bool f3=(((a[0]-'A'<3)&&(b[0]-'A'<3))||((a[0]-'A'>=3)&&(b[0]-'A'>=3)));
    bool f4=(((abs((int)a[0]-(int)b[0])==1)&&(!(a[0]=='C'&&b[0]=='D'))&&(!(a[0]=='D'&&b[0]=='C')))||((a[0]=='D')&&(b[0]=='F'))||((a[0]=='F')&&(b[0]=='D')));
    cout<<f1;
    cout<<(f1&&f2);
    cout<<(f1&&f2&&f3);
    cout<<(f1&&f2&&f3&&f4);
    return 0;
}
