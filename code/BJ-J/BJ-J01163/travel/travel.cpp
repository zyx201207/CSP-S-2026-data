#include<bits/stdc++.h>
//#define fin cin
//#define fout cout
using namespace std;
int main(){
    string a,b,c,d;
    ifstream fin;
    ofstream fout;
    fin.open("travel.in");
    fout.open("travel.out");
    fin>>a>>b>>c>>d;
    if(a!=c){
        fout<<"0000";
    }else if(b[0]!=d[0]||b[1]!=d[1]){
        fout<<"1000";
    }else if((b[2]<='C'&&d[2]>='D')||(d[2]<='C'&&b[2]>='D')){
        fout<<"1100";
    }else if(b[2]-d[2]!=1&&d[2]-b[2]!=1){
        fout<<"1110";
    }else{
        fout<<"1111";
    }
    fin.close();
    fout.close();
    return 0;
}