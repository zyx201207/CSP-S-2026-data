#include<bits/stdc++.h>
using namespace std;
string r1,r2,s1,s2;
bool checkfunc1(int t1,int t2){
    if ((t1=='A'||t1=='B'||t1=='C')&&(t2=='A'||t2=='B'||t2=='C')) {
        return true;
    }else{
        return false;
    }
}
bool checkfunc2(int t1,int t2){
    if ((t1=='D'||t1=='F')&&(t2=='D'||t2=='F')) {
        return true;
    }else{
        return false;
    }
}
void check4(){
    int t1=r2[2]-'A';
    int t2=s2[2]-'A';
    if (abs(t1-t2)==1) {
        cout << 1 << endl;
    }else {
        cout << 0 << endl;
    }
}
void check3(){
    char t1=r2[2];
    char t2=s2[2];
    if (checkfunc1(t1,t2)||checkfunc2(t1,t2)) {
        cout << 1;
        check4();
    }else {
        cout << "00" << endl;
    }
}
void check2(){
    //string t1=r2[0]+r2[1];
    //string t2=s2[0]+s2[1];
    string t1=r2.substr(0,2);
    string t2=s2.substr(0,2);
    if (t1==t2) {
        cout << 1;
        check3();
    }else {
        cout << "000" << endl;
    }
}
void check1(){
    if (r1==s1) {
        cout << 1;
        check2();
    }else {
        cout << "0000" << endl;
    }
}
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> r1 >> r2 >> s1 >> s2;
    check1();
    return 0;
}
