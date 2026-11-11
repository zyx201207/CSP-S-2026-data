#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,as,b,bs;
    cin >> a >> as >> b >> bs;
    int c1,s1,c2,s2;
    c1=(a[1]-'0')*10+(a[0]-'0');
    c2=(b[1]-'0')*10+(b[0]-'0');
    if(c1!=c2) cout << "0000\n";
    else{
        cout <<"1";
        s1=(as[1]-'0')*10+(as[0]-'0');
        s2=(bs[1]-'0')*10+(bs[0]-'0');
        if(s1!=s2) cout <<"000\n";
        else{
            cout <<"1";
            if(abs(as[2]-bs[2])!=1&&((as[2]!='A'&&bs[2]!='C')&&(as[2]!='C'&&bs[2]!='A')))cout <<"00\n";
            else if(abs(as[2]-bs[2])==1&&((as[2]=='D'&&bs[2]=='C')||(as[2]=='C'&&bs[2]=='D')))cout <<"00\n";
            else{
                cout <<"1";
                if(abs(as[2]-bs[2])!=1)cout <<"0\n";
                else cout <<"1\n";
            }
        }
    }
}
