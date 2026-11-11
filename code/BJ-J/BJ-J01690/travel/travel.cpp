#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[4] = { };
    char s1[4] = { };
    char c2[5] = { };
    char s2[5] = { };
    int a[4] = { };
    scanf(c1,"%s");
    scanf(s1,"%s");
    scanf(c2,"%s");
    scanf(s2,"%s");
    if(c1[0] == c2[0] && c1[1] == c2[1]){
        a[0] = 1;
        if((s1[1] == s2[1]) && (s1[0] == s2[0])){
            if(((s1[2] == ("D"||"F")) && (s2[2] == ("D"||"F"))) || (s1[2] == ("A"||"B"||"C")) && (s2[2] == ("A"||"B"||"C"))){
                a[2] = 1;
                /*if(s1[2] == "A" && s2[2] == "B")a[3] = 1;
                else if(s1[2] == "B" && s2[2] == ("A" || "C"))a[3] = 1;
                else if(s1[2] == "C" && s2[2] == "B")a[3] = 1;
                else if(s1[2] == "F" && s2[2] == "D")a[3] = 1;
                else if(s1[2] == "D" && s2[2] == "F")a[3] = 1;
                else a[3] = 0;*/
            }
            else{
                a[2] = 0;
                a[3] = 0;
            }
        }
        else{
            a[1] = 0;
            a[2] = 0;
            a[3] = 0;
        }

    }
    else{
        a[0] = 0;
        a[1] = 0;
        a[2] = 0;
        a[3] = 0;
    }
    cout << a[0] << a[1] << a[2] << a[3];
    return 0;
}
