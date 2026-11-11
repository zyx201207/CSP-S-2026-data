#include<iostream>
using namespace std;
int aa1,aa2,aa3,aa4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,a1,b1;
    cin>>a>>b>>a1>>b1;
    if(a==a1){
        aa1=1;
    }
    if(b[0]==b1[0]&&b[1]==b1[1]){
        aa2=1;
    }
    if((b[2]=='D'&&b1[2]=='F')||(b[2]=='F'&&b1[2]=='D')||(b[2]=='A'&&b1[2]=='B')||(b[2]=='B'&&b1[2]=='A')||(b[2]=='B'&&b1[2]=='C')||(b[2]=='C'&&b1[2]=='B')||(b[2]=='A'&&b1[2]=='C')||(b[2]=='C'&&b1[2]=='A')){
        aa3=1;
    }
    if((b[2]=='D'&&b1[2]=='F')||(b[2]=='F'&&b1[2]=='D')||(b[2]=='A'&&b1[2]=='B')||(b[2]=='B'&&b1[2]=='C')||(b[2]=='B'&&b1[2]=='A')||(b[2]=='C'&&b1[2]=='B')){
        aa4=1;
    }
    cout<<aa1<<aa2<<aa3<<aa4;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

