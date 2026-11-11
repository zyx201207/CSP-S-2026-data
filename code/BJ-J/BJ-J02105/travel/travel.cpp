#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a,b,c,d;
int m = 0,n = 0,p = 0,q = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    a = s1[0];
    b = s1[1];
    c = s2[0];
    d = s2[1];
    if(c1 == c2){
        m += 1;
        if(a == c && b == d){
            n += 1;
            if(s1[2] == "A" || s1[2] == "B" || s1[2] == "C"){
                if(s2[2] == "A" || s2[2] == "B" || s2[2] == "C"){
                    p += 1;
                    if(s1[2] == "A" && s2[2] == "B"){
                        q += 1;
                    }
                    if(s1[2] == "B" && s2[2] == "A"){
                        q += 1;
                    }
                    if(s1[2] == "B" && s2[2] == "C"){
                        q += 1;
                    }
                    if(s1[2] == "C" && s2[2] == "B"){
                        q += 1;
                    }
                }
            }
            if(s1[2] == "D" || s1[2] == "F"){
                if(s2[2] == "D" || s2[2] == "F"){
                    p += 1;
                    q += 1;
                }
            }
        }
    }
    if(m == 0){
        cout<<"否 否 否 否";
    }
    if(m == 1&& n == 0){
        cout<<"是 否 否 否";
    }
    if(m == 1 && n == 1 && p == 0){
        cout<<"是 是 否 否";
    }
    if(m == 1 && n == 1 && p == 1 && q == 0){
        cout<<"是 是 是 否";
    }
    if(m == 1 && n == 1 && p == 1 && q == 1){
        cout<<"是 是 是 是";
    }
    return 0;
}