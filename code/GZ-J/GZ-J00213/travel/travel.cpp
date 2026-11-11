//GZ-J00213遵义市第四中学周高逸

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s1, s2, s3, s4;
int box=0, line=0, lr=0;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> s1 >> s2 >> s3 >> s4;
    if(s1==s3){
        cout << 1;
        box = 1;
    }
    else cout << 0;
    if(s2[0]==s4[0] && s2[1]==s4[1] && box){
        cout << 1;
        line = 1;
    }
    else cout << 0;
    if(((s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C') || ((s2[2]=='D'&&s4[2]=='F')||(s4[2]=='F'&&s4[2]=='D'))) && box && line){
        cout << 1;
        lr = 1;
    }
    else cout << 0;
    if((((s2[2]=='A'&&s4[2]=='B')||(s4[2]=='B'&&s4[2]=='A') || (s2[2]=='C'&&s4[2]=='B')||(s4[2]=='B'&&s4[2]=='C')) || ((s2[2]=='D'&&s4[2]=='F')||(s4[2]=='F'&&s4[2]=='D'))) && box && line && lr)
        cout << 1;
    else cout << 0;

    return 0;
}
