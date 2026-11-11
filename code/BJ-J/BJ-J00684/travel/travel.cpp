#include<fstream>
#include<string>
using namespace std;
int  main(){
    ifstream fin("travel.in");
    ofstream fout("travel.out");
    string c1,s1,c2,s2;
    fin>>c1>>s1>>c2>>s2;
    if(c1==c2) {
        fout<<'1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            fout<<'1';
            if((s1[2]>'C'&&s2[2]>'C')||(s1[2]<='C'&&s2[2]<='C')){
                fout<<'1';
                if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C')||(s2[2]=='D'&&s1[2]=='F')) fout<<'1';
                else fout<<'0';
            }
            else fout<<"00";
        }
        else fout<<"000";
    }
    else fout<<"0000";
    return 0;
}
