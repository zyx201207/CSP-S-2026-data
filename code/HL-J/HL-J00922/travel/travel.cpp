#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    bool o = true;
    if(c1 == c2){
        cout<<1;
    }else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    int line1 = 10*(s1[0]-'0')+(s1[1]-'0');
    int line2 = 10*(s2[0]-'0')+(s2[1]-'0');
    if(line1 == line2){
        cout<<1;
    }else{
        cout<<0<<0<<0;
        return 0;
    }
    if(s1[2] <= 'C'&&s1[2] >= 'A' && s2[2] <= 'C' && s2[2] >= 'A'||s1[2] <= 'F'&&s1[2] >= 'D' && s2[2] <= 'F' && s2[2] >= 'D'){
        cout<<1;
        o = true;
    }else{
        cout<<0<<0;
        return 0;
    }
    if(s1[2] == s2[2]-1 && o == true||s1[2] == s2[2]+1&&o == true){
        cout<<1;
    }else{
        cout<<0;
    }

    return 0;
}
