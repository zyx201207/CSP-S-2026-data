#include <bits/stdc++.h>
using namespace std;
int a1=0;
int a2=0;
int a3=0;
int a4=0;
string st="ABD";
string st2="BCF";

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a1=1;
    }
    if(a1 && s1[0]==s2[0] && s1[1]==s2[1]){
        a2=1;
    }
    if(a2 && s1[2]<='C' && s2[2]<='C'){
        a3=1;
    }
    if(a2 && s1[2]>='D' && s2[2]>='D'){
        a3=1;
    }
    if(a3)
    {
        for(int i=0;i<3;i++){
            if(s1[2]==st[i] && s2[2]==st2[i]){
                a4=1;
            }
            if(s1[2]==st2[i] && s2[2]==st[i]){
                a4=1;
            }
        }
    }
    cout << a1 << a2 << a3 << a4 << "\n";
    return 0;
}
