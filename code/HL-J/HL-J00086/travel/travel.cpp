#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int x,p,c;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1[0]==c2[0] && c1[1]==c2[1]){
        cout << 1;
        x=1;
    }else cout << 0;
    if(s1[0]==s2[0] && s1[1]==s2[1] && x){
        cout << 1;
        p=1;
    }else cout << 0;
    if(((s1[2]>='A' && s1[2]<='C') && (s2[2]>='A' && s2[2]<='C') || (s1[2]>='D' && s1[2]<='F' && s1[2]!='E') && (s2[2]>='D' && s2[2]<='F' && s2[2]!='E')) && x && p){
        cout << 1;
    c=1;
    }else cout << 0;
    if((s1[2]=='A' && s2[2]=='B' || s1[2]=='B' && s2[2]=='C' || s1[2]=='D' && s2[2]=='F' || s1[2]=='B' && s2[2]=='A' || s1[2]=='C' && s2[2]=='B' || s1[2]=='F' && s2[2]=='D') && s1[2]!=s2[2] && x && p && c) cout << 1;
    else cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
