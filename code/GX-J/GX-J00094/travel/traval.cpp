#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ca,sa,cb,sb;
    cin >> ca >> sa >> cb >> sb;
    if(ca == cb){
        cout << 1;
    }else{
        cout << 0000;
        return 0;
    }
    string sx,sy;
    sx = sa,sy = sb;
    sx.erase(2,1);
    sy.erase(2,1);
    if(sx == sy){
        cout << 1;
    }else{
        cout << 000;
        return 0;
    }
    sx = sa,sy = sb;
    sx.erase(0,2);
    sy.erase(0,2);
    bool flag1 = false,flag2 = false;
    if(sx == "D" || sx == "F") flag1 = true;
    if(sy == "D" || sy == "F") flag2 = true;
    if(flag1 == flag2){
        cout << 1;
    }else{
        cout << 0;
    }
    sx = sa,sy = sb;
    sx.erase(0,2);
    sy.erase(0,2);
    string sn,sm;
    sn = sa,sm = sb;
    sn.erase(2,1),sm.erase(2,1);
    int a,b,c,d;
    if(sx == "A"){
        a = 1;
    }else if(sx == "B"){
        a = 2;
    }else if(sx == "C"){
        a = 3;
    }else if(sx == "D"){
        a = 4;
    }else{
        a = 5;
    }
    if(sy == "A"){
        b = 1;
    }else if(sy == "B"){
        b = 2;
    }else if(sy == "C"){
        b = 3;
    }else if(sy == "D"){
        b = 4;
    }else{
        b = 5;
    }
    if(sn == "01"){
        c = 1;
    }else if(sn == "02"){
        c = 2;
    }else if(sn == "03"){
        c = 3;
    }else if(sn == "04"){
        c = 4;
    }else if(sn == "05"){
        c = 5;
    }else if(sn == "06"){
        c = 6;
    }else if(sn == "07"){
        c = 7;
    }else if(sn == "08"){
        c = 8;
    }else if(sn == "09"){
        c = 9;
    }else if(sn == "10"){
        c = 10;
    }else if(sn == "11"){
        c = 11;
    }else if(sn == "12"){
        c = 12;
    }else if(sn == "13"){
        c = 13;
    }else if(sn == "14"){
        c = 14;
    }else if(sn == "15"){
        c = 15;
    }else if(sn == "16"){
        c = 16;
    }else if(sn == "17"){
        c = 17;
    }else{
        c = 18;
    }
    if(sm == "01"){
        d = 1;
    }else if(sm == "02"){
        d = 2;
    }else if(sm == "03"){
        d = 3;
    }else if(sm == "04"){
        d = 4;
    }else if(sm == "05"){
        d = 5;
    }else if(sm == "06"){
        d = 6;
    }else if(sm == "07"){
        d = 7;
    }else if(sm == "08"){
        d = 8;
    }else if(sm == "09"){
        d = 9;
    }else if(sm == "10"){
        d = 10;
    }else if(sm == "11"){
        d = 11;
    }else if(sm == "12"){
        d = 12;
    }else if(sm == "13"){
        d = 13;
    }else if(sm == "14"){
        d = 14;
    }else if(sm == "15"){
        d = 15;
    }else if(sm == "16"){
        d = 16;
    }else if(sm == "17"){
        d = 17;
    }else{
        d = 18;
    }
    if(abs(a-b) == 1 && abs(c - d) <= 1){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}
