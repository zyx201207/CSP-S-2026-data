#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(string a,string b){
    if(a[0]==b[0] && a[1]==b[1]) return true;
    return false;
}

bool zgy(string a,string b){
    char p=a[2],q=b[2];

    if(('A'<=p && p<='C' && 'A'<=q && q<='C')||('D'<=p && p<='F' && 'D'<=q && q<='F')) return true;
    return false;
}

bool c3(char a,char b){
    if(a>b) swap(a,b);
    if(a=='A'&&b=='B') return true;
    if(a=='B'&&b=='C') return true;
    if(a=='D'&&b=='F') return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(check(s1,s2)){
            cout<<"1";
            if(zgy(s1,s2)){
                cout<<"1";
                if(c3(s1[2],s2[2])) cout<<"1";
                else cout<<"0";
            }
            else{
                cout<<"00";
                return 0;
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
