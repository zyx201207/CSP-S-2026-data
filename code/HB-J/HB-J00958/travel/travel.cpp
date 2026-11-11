#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s;
string S1="A",S2="B",S3="C",S4="D",S5="F";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            s1=s1[2];
            s2=s2[2];
            if((s1=="A" || s1==S2 || s1==S3) && (s2==S1 || s2==S2 || s2==S3) || (s1==S4 || s1==S5) && (s2==S4 || s2==S5)){
                if(s1==S1 && s2==S2 || s1==S2 && s2==S3 || s1==S4 && s2==S5)s="1111";
                else s="1110";
            }
            else s="1100";
        }
        else s="1000";
    }
    else s="0000";
    cout << s;
    return 0;
}
