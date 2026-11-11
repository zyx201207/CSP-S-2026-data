#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int toNumber(string s){
    int num=0;
    for(int i=0;i<s.size();i++){
        if(s[i]<'0'||s[i]>'9') break;
        num=num*10+(s[i]-'0');
    }
    return num;
}
char toABC(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A'&&s[i]<='Z') return s[i];
    }
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    cout<<(toNumber(c1)==toNumber(c2));
    cout<<(toNumber(c1)==toNumber(c2)&&toNumber(s1)==toNumber(s2));
    bool abc=((toABC(s1)>='A'&&toABC(s1)<='C'&&toABC(s2)>='A'&&toABC(s2)<='C')||(toABC(s1)>='D'&&toABC(s1)<='F'&&toABC(s2)>='D'&&toABC(s2)<='F'));
    cout<<(toNumber(c1)==toNumber(c2)&&toNumber(s1)==toNumber(s2)&&abc);
    cout<<(toNumber(c1)==toNumber(c2)&&toNumber(s1)==toNumber(s2)&&abc&&(toABC(s1)+1==toABC(s2)||toABC(s2)+1==toABC(s1)||(toABC(s1)=='D'&&toABC(s2)=='F'||toABC(s1)=='F'&&toABC(s2)=='D')));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
