#include<iostream>
#include<fstream>
using namespace std;
//Trick||Treat!
int c1,c2;
string s1,s2,t1,t2;
int main(){
    ifstream cin("travel.in");
    ofstream cout("travel.out");
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    bool a=c1==c2;
    bool b=(s1[0]==s2[0])&&(s1[1]==s2[1]);
    bool c=b&&(s1[2] <= 'C' && s2[2]<='C')||(s1[2]>'C' && s2[2]>'C');
    bool d=b&&c&&abs(s1[2]-s2[2])==1;
    cout<<a<<b<<c<<d;
    return 0;
}
