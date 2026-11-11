#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    char c1[3],s1[3],c2[3],s2[3];
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1,s1,c2,s2;
    char f1,f2,f3,f4;
    int t1 = 0,t2 = 0,t3 = 0,t4 = 0;
    int p1,p2;
    if(s1[2] == "A"){
        p1 = 1;
        }
    if(s1[2] == "B"){
        p1 = 2;
        }
    if(s1[2] == "C"){
        p1 = 3;
        }
    if(s1[2] == "D"){
        p1 = 4;
        }
    if(s1[2] == "E"){
        p1 = 5;
    }
    if(s1[2] == "F"){
        p1 = 6;}
    if(s2[2] == "A"){
        p2 = 1;}
    if(s2[2] == "B"){
        p2 = 2;}
    if(s2[2] == "C"){
        p2 = 3;}
    if(s2[2] == "D"){
        p2 = 4;}
    if(s2[2] == "E"){
        p2 = 5;}
    if(s2[2] == "F"){
        p2 = 6;}
    if(c1 == c2){
        t1 = t1 + 1;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1]){
        t2 = t2 + 1;
    }
    if(t2 == 1 && p1 <= 3 && p2 <= 3){
        t3 = t3 + 1;
    }
    if(p1 - p2 == 1 || p2 - p1 == 1){
        t4 = t4 + 1;
    }
    char f1[3] = char(t1),f2[3] = char(t2),f3[3] = char(t3),f4[3] = char(t4);
    cout << f1 << f2 << f3 << f4;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
