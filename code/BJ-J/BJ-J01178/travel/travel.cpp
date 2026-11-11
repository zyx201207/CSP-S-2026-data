#include<bits/stdc++.h>
using namespace std;
string a;
string b;
string c;
string d;
string ans="";
int ffir=0;
int fsec=0;
int fthi=0;
int ffor=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    if(a==c){
        ffir=1;
    }if((b[0]==d[0])&&(b[1]==d[1])&&a==c){
        fsec=1;
    }if(((b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C'))&&((b[0]==d[0])&&(b[1]==d[1])&&a==c)){
        fthi=1;
    }if(((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))&&((b[0]==d[0])&&(b[1]==d[1])&&a==c)&&(int(b[2]-d[2])==1||int(d[2]-b[2])==1)){
        ffor=1;
    }
    if(ffir==1){
        ans+="1";
    }else{
        ans+="0";
    }
    if(fsec==1){
        ans+="1";
    }else{
        ans+="0";
    }
    if(fthi==1){
        ans+="1";
    }else{
        ans+="0";
    }
    if(ffor==1){
        ans+="1";
    }else{
        ans+="0";
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
