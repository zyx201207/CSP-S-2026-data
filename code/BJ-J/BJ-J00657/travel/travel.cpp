#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream fin("travel.in");
    ofstream fout("travel.out");
    string c1,s1,c2,s2;
    fin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        fout<<"1";
        if(s1[0]+s1[1]==s2[0]+s2[1]){
            fout<<"1";
            char a1=s1[2],a2=s2[2];
            if(a1>'C'&&a2>'C'){
                fout<<"11\n";
            }else if(a1<'D'&&a2<'D'){
                fout<<"1";
                if(a1<'C'&&a2<'C'){
                    fout<<"1\n";
                }else if(a1>'A'&&a2>'A'){
                    fout<<"1\n";
                }else{
                    fout<<"0\n";
                }
            }else{
                fout<<"00\n";
            }

        }else{
            fout<<"000\n";
        }
    }else{
        fout<<"0000\n";
    }
    return 0;
}
